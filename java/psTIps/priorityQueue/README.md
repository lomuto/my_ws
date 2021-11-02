# 우선순위큐

```java
PriorityQueue<Obj> pq = new PriorityQueue<>();  // 작은거 먼저 나옴

PriorityQueue<Obj> pq = new PriorityQueue<>(Collections.reverseOrder());  // 작은거 먼저 나옴
```

자바에서 우선순위큐는 선언 시 마지막에 `Collections.reverseOrder()` 넣어주면 된다. C++의 `greater<>` 같은거인듯
