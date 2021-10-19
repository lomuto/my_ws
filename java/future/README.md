# Java에서 대량 requset의 비동기 처리

2021 네트워크 프로그래밍 중간고사 대비 프로그래밍 task 하면서 느낀점.

PHP에서 멀티프로세싱으로 요청들을 처리하다가, Process를 만드는데 드는 비용이 expensive해서 나온게 Spring의 threadPool.  
Spring의 threadPool에서 non-blocking하게 처리하고자 나온게 async-non-blocking의 nodejs다.  
Nodejs에서는 async함수에 await키워드만 박으면 비동기가 됐는데 자바에서 이를 구현하는게 까다로웠다.

```java
ExecutorService threadPool = Executors.newFixedThreadPool(THREAD_COUNT);
Future<SomeType> future0 = threadPool.submit(new Thread(() -> {
    System.out.println("Worker thread!");
    return ...;
    }));
Future<SomeType> future1 = threadPool.submit(new Thread(() -> {
    System.out.println("Worker thread!");
    return ...;
    }));

future0.get();
future1.get();

System.out.println("Main thread finished!")
...
```

ExecutorService클래스를 활용해서 스레드풀을 돌려 멀티스레드 task를 동기적으로 관리해주는 방법이다. **다만 이 방법은 task의 개수가 한정적일때만 유효하다...** 다량의 멀티스레드 task들을 main에서 기다려주려면 다음과 같은 방법이 있다.

1.  ```java
    // main thread
    ...
    while(exitThreadCount < threadCount) {
        Thread.yield();
    }
    ```

    task들 내부에서 종료 시 synchronize하게 `exitThreadCount`를 증가시켜주어 모든 task가 완료될때까지 main스레드에서 spinning시키고, spinning으로 인한 오버헤드를 최대한 막기 위해 자원을 매번 놓아주게 한다. 문제는 OS가 스케줄링을 어떻게 할지 몰라 main thread를 자주 running시키면 성능이 낮아진다. **즉 속도의 보장이 안됨**

2.  ```java
    List<Thread> threadList = new LinkedList<>();
    for(int i=0; i<n; i++) {
        if(i%k) {
            for(Thread thread : threadList) {
                thread.join();
            }
            threadList.clear();
        }
        Thread t = new Thread(...);
        t.srart();
        threadList.add(t);
    }
    ```
    k개씩 끊어서 실행시키고 join하는 방법. 이건 I/O Bound한 작업일경우 굉장히 비효율적으로 돈다.

## solution

```java
ExecutorService threadPool = Executors.newFixedThreadPool(THREAD_COUNT);
CompletionService<Boolean> completionService = new ExecutorCompletionService<>(threadPool);
...
for (int c = 1; c <= 50; c++) {
            for (int d = 1; d <= 60; d++) {
                completionService.submit(new Task(...));
                completionService.submit(new Task(...));
            }
        }

        int received = 0;

        while (received < TOTAL_FILE_COUNT) {
            Future<Boolean> resultFuture = completionService.take();    // Block untill at least one task finished
            try {
                Boolean ret = resultFuture.get();
                if (ret) {
                    received++;
                }
            } catch (Exception e) {
                received++;
            }
        }
```

completionService 인스턴스를 통해 task들을 submit하고, 미래에 완료될 task들을 `take`로 받아온다. `take`로 받아온 Future 리스트들에서 get을 호출할 때 마다 **비동기적으로 처리된 task들 중 submit된 순서 상관없이 종료가 되면 get으로 return을 넘겨받을 수 있다**.  
`received` 변수로 submit한 task들 카운팅.

return값이 `false`일 경우 timeout excepion이 발생한 경우.  
이는 `Callable`의 call함수 안에서 Exception catch구문에서 task를 만들어서 다시 쏴주는거로 해결했다.

```java
...
} catch (SocketException | SocketTimeoutException e) {
            completionService.submit(new Task(...));
            return false;
        }
        ...
```
