# 블랙잭

[https://www.acmicpc.net/problem/2798](https://www.acmicpc.net/problem/2798)

dfs긴 한데 완전탐색에 가깝다.

두달밖에 안됐는데 내 풀이를 내가 아예 까맞게 까먹고 봐도 이해하는데 한참이 걸렸다...

```cpp
for(...){
    for(...) {
        for(...) {

        }
    }
}
```

이렇게 풀 문제를, 재귀함수를 이용해 for문의 최대깊이인 3을 지정해주면서

```cpp
dfs(int count, int sum) {
    // sum 확인
    // count가 3보다 깊으면 종료
    for(...) {
        if(isVisited[i] == false) {
            isVisited[i] = true;
            dfs(count+1, sum + v[i]);
            // 재귀 끝나고 방문처리 종료
            isVisited[i] = false;
        }
    }
}
```

아니 두달만에 멍청해진건지... 내가 어떻게 이 풀이를 고안했는지 신기할 따름이다.
