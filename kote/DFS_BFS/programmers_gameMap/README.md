# 미로 최단거리

[https://programmers.co.kr/learn/courses/30/lessons/1844](https://programmers.co.kr/learn/courses/30/lessons/1844)

---

## DFS ver

DFS로 풀면 TLE. bfs 업데이트 예정

- 행의 길이가 `n` 열의 길이가 `m` 일 때 `MAP[n+2][m+2]` 해서 boundary 설정
- 저번에 배운 memset 사용 잘 했음

<br/>

일반적인 DFS 미로찾기랑 다른 점: 도착만 하면 장땡이 아니라 최소 거리를 찾아야함

해결책: 유효한 길이 `1`로, 유효하지 않은 길이 `0` 인 입력으로 주어질 때 유효한 길이면 `MAP` 의 원소값을 최대값 (`10001`)으로 설정.

일반적인 DFS처럼 왔다갔다 할 때

```cpp
if(MAP[next_r][next_c] > cnt){
    MAP[next_r][next_c] = cnt;
    DFS(next_r,next_c,cnt+1);
}
```

같이 해주면 cnt가 최소인 값으로 경로가 설정됨.

**경로값이 최소가 아니면 방문하지를 않으니 따로 `VISITED[][]` 같은거 안둬도 된다.**
