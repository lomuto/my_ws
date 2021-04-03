# 더 나은 DFS 설계

[https://algospot.com/judge/problem/read/BOGGLE#](https://algospot.com/judge/problem/read/BOGGLE#)

DFS 장에서 이 문제를 설명해줬는데, 정작 풀이는 DP 로 풀어야지 안그럼 시간초과가 나온다.  
pass는 아니지만 좋은 dfs 설계방법을 찾아서 적어본다.

---

### 기존 쓰던 방법

```cpp
void search(int x, int y, string str, int idx, int &ans) {
    if (idx == str.size())
        ans = 1;
    if (x < 4 && BOGGLE[x + 1][y] == str[idx]) {
        search(x + 1, y, str, idx + 1, ans);
    }
    if (y < 4 && x < 4 && BOGGLE[x + 1][y + 1] == str[idx]) {
        search(x + 1, y + 1, str, idx + 1, ans);
    }
    if (y < 4 && BOGGLE[x][y + 1] == str[idx]) {
        search(x, y + 1, str, idx + 1, ans);
    }
    if (y < 4 && BOGGLE[x - 1][y + 1] == str[idx]) {
        search(x - 1, y + 1, str, idx + 1, ans);
    }
    if (x > 0 && BOGGLE[x - 1][y] == str[idx]) {
        search(x - 1, y, str, idx + 1, ans);
    }
    if (y > 0 && x > 0 && BOGGLE[x - 1][y - 1] == str[idx]) {
        search(x - 1, y - 1, str, idx + 1, ans);
    }
    if (y > 0 && BOGGLE[x][y - 1] == str[idx]) {
        search(x, y - 1, str, idx + 1, ans);
    }
    if (y > 0 && x < 4 && BOGGLE[x + 1][y - 1] == str[idx]) {
        search(x + 1, y - 1, str, idx + 1, ans);
    }
}
```

문제조건이 8방향 전부 뒤져보라는거여서 좀 길다. 보통 미로찾기? 같은건 4방향만 찾을텐데.  
함수를 재귀적으로 호출 하되 8방향의 좌표를 전부 탐색해보고, 조건에 맞으면 그 방향으로 이동한다.  
**이동하려는 방향이 범위를 벗어나는지 꼭 체크해야한다** 안그러면 조건문에서 접근하는것 에서 segfault 오휴가 난다.  
그래서 나는 `&&` 연산자 특성 활용해 범위검색을 먼저 해줬다.  
근데 이러면 코드가 더럽고 작성하는데도 오래걸린다. 좋은 코드를 보자.

---

### 좋은 방법

```cpp
int dx[8] = {0, 1, 1, 0, -1, -1, 1, -1};
int dy[8] = {1, 0, 1, -1, 0, -1, -1, 1};

void search(int x, int y, string str, int idx, int &ans) {
    if (!(x < 5 && x > -1 && y > -1 && y < 5))
        return;
    if (str[idx] == BOGGLE[x][y])
        ;
    else
        return;

    if (idx == str.size() - 1) {
        ans = 1;
        return;
    }

    for (int i = 0; i < 8; i++)
        search(x + dx[i], y + dy[i], str, idx + 1, ans);
}
```

이동하려는 좌표를 배열에 저장해 index 별로 쌍을 짓는다. `(dx[i],dy[i])` 처럼.  
그리고 for문을 통해 전부를 탐색한다.  
범위검색을 함수 초반부에 해주어 가독성도 높였다.
