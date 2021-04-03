# 침투

[https://www.acmicpc.net/problem/13565](https://www.acmicpc.net/problem/13565)

## 반성해야할점

### 1. 반복문 안의 조건문에서 방문처리 하니까 방문처리 안되는 곳 생김. 무조건 반복문 최상단에 방문처리 하기

```cpp
if (r < ROW - 1 && MAP[r + 1][c]) {
    v.push_back(make_pair(r, c));
    r++;
    MAP[r][c] = false;
} else if (c < COL - 1 && MAP[r][c + 1]) {
    v.push_back(make_pair(r, c));
    c++;
    MAP[r][c] = false;
} else if (r > 0 && MAP[r - 1][c]) {
    v.push_back(make_pair(r, c));
    r--;
    MAP[r][c] = false;
} else if (c > 0 && MAP[r][c - 1]) {
    v.push_back(make_pair(r, c));
    c--;
    MAP[r][c] = false;
} else {
    /*
        여기 방문처리 안돼서 헤맸음
    */
    if (v.empty()) {
        break;
    }
    pair<int, int> tmp = v.back();
    r = tmp.first;
    c = tmp.second;
    v.pop_back();
}
```

---

21.4.3 업데이트

지금까지는 배열의 boundary 안넘으려고 인덱스 조건처리를 해줬는데  
PS에서 메모리 아껴서 쓸데없다.

배열의 최대 크기가 NxN으로 주어지면 **int MAP[N+2][n+2]** 짜리 배열을 정적변수에 선언하자. 그게 훨씬 편하다.

그리고 main 함수 진입직후

```cpp
memset(MAP,-1,sizeof(MAP));
```

으로 2차원 배열 전체를 내가 설정한 임의의 경계숫자(`-1`) 로 초기화 한다. 간혹 쓰레기 값이 우연찮게 조건에 맞아떨어지는 경우가 있음

마지막으로 배열 입력받을 때

```cpp
int r,c; // r=세로길이, c=가로길이

cin >> r >> c;

for(int i=1; i<=r; i++){
    for(int j=i; j<=c; j++)
        MAP[i][j] = //...
}
```

이렇게 입력 받으면 배열 테두리에 경계가 생기면서 seg falut 고려 안해도 된다.

---

```cpp
int MAP[1010][1010];
int r, c;
int ans = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(int x, int y){
    MAP[x][y] = 1; // 방문처리

    if(x == r){ // 끝에 닿았음
        ans = 1;
        return;
    }

    for(int i=0; i<4; i++){
        if(MAP[x+dx[i]][y+dy[i]]==0)
            DFS(x+dx[i],y+dy[i]);
    }
}
```
