# 최소거리미로탐색

[https://www.acmicpc.net/problem/2178](https://www.acmicpc.net/problem/2178)

DFS로 풀 시 시간초과가 나는 문제.  
재귀호출에서 cnt값을 인자로 넘겨주면 구현하는데는 편하지만 느리다.

BFS 사용법을 본격적으로 익힌 문제.

---

<br/>

## 메모리초과

```cpp
while (!(q.empty())) {
        R = q.front().second.first;
        C = q.front().second.second;
        cnt = q.front().first;
        q.pop();
        MAP[R][C] = cnt;

        for (int i = 0; i < 4; i++) {
            int next_r = R + dr[i];
            int next_c = C + dc[i];
            if (MAP[next_r][next_c] && MAP[next_r][next_c] > cnt + 1)
                q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
        }
    }
```

구현자체는 문제가 없다. 하지만 제출 시 `메모리초과` 가 발생한다.  
이 메모리초과는 탐색 시 **동일 좌표가 여러번 큐에 push 되기 때문에 일어난다.**  
이를 방지하기 위해서는 방문처리를 위한 map 을 하나 더 두어야 하지만

```
동일 좌표를 최초 한번만 방문하게 해준다면 다른 경로에서 최소경로를 이을 수 있음이 무시되지 않을까
```

하는 생각에 많이 고민했었다.

**결과가 최소라면 이는 최소 경로들의 합** 이므로 위의 경우는 무시해도 되는 case였다.

---

<br/>

## 방문처리와 좌표변경 시점

```cpp
// 틀린곳이 두군데 있다.
while (!(q.empty())) {
        V[next_r][next_c] = 1;
        int next_r, next_c;
        for (int i = 0; i < 4; i++) {
            next_r = r + dr[i];
            next_c = c + dc[i];
            if (V[next_r][next_c] == 0 && MAP[next_r][next_c] > 0) {
                q.push(make_pair(next_r, next_c));
                MAP[next_r][next_c] = MAP[r][c] + 1;
            }
        }
        r = q.front().first;
        c = q.front().second;
        q.pop();
    }
```

- 방문처리  
  DFS에서는 방문처리를 반복문의 시작점에 해주었다. 좌표를 자료구조에 기록하는 시점과 방문하는 시점이 동일한 DFS는 방문처리를 방문 시점에 해주어도 되지만

```
큐에 방문처리를 하는 시점과 방문 시점이 상이할 수 밖에 없는 BFS는 반드시 임의의 좌표에서 주변 좌표 탐색 시 방문이 가능한 좌표를 큐에 push 할때 방문처리도 같이 해주어야 한다.
```

따라서

```cpp
if (V[next_r][next_c] == 0 && MAP[next_r][next_c] > 0) {
    q.push(make_pair(next_r, next_c));
    V[next_r][next_c] = 1;  // 방문처리 여기로 옮겨준다
    MAP[next_r][next_c] = MAP[r][c] + 1;
}
```

---

- 좌표 변경 시점

지금 위의 예시처럼 바뀐 좌표를 밑에서 업데이트 해주면 **마지막 하나 남은 좌표의 경우 업데이트 되고 나서 큐가 비게 되므로 그 좌표에 대한 주변탐색 또는 이동 없이 반복문이 종료된다.**

```cpp
while(1){
    ...
    if(q.empty())
        break;
    else
    /*좌표 업데이트*/
}
```

이렇게 반복문을 만들던가, 아님 while문의 종료조건에 `!(q.empty())` 를 넣었으면

```cpp
while(!(q.empty())){
    /*좌표 업데이트*/
    ...
}
```

이렇게 해주어야 한다.

- bfs 함수 최종

```cpp
void BFS() {
    int r = 1, c = 1;
    q.push(make_pair(r, c));
    V[r][c] = 1;

    while (!(q.empty())) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        int next_r, next_c;
        for (int i = 0; i < 4; i++) {
            next_r = r + dr[i];
            next_c = c + dc[i];
            if (V[next_r][next_c] == 0 && MAP[next_r][next_c] > 0) {
                q.push(make_pair(next_r, next_c));
                V[next_r][next_c] = 1;
                MAP[next_r][next_c] = MAP[r][c] + 1;
            }
        }
    }

    return;
}
```
