# 숨바꼭질

[https://www.acmicpc.net/problem/1697](https://www.acmicpc.net/problem/1697)

<br/>
   
보자마자 bfs 풀이가 떠올랐지만 메모리 터지지 않을까 생각이 든 문제.   
   
예상대로 8%에서 메모리가 터졌고 이유는 방문처리를 못했음.   
    
좌우로 왔다갔다 할 수 있으므로    
```
1 -> 2 -> 1 -> 2 -> 1 -> 2
```   
   
이런식으로 불필요한 움직임까지 큐에 보관중.   
   
해당 문제를 해결하기 위해 `unordered_set` 으로 방문처리.
