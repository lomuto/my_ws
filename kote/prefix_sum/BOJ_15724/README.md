# 2차원 부분합

[https://www.acmicpc.net/problem/15724](https://www.acmicpc.net/problem/15724)

---

1차원이 아닌 2차원 부분합 문제.

2차원 배열 `MAP`이 주어지고 MAP의 부분합 `PSUM` 이 있을 때

```cpp
for(int i=0; i<r; i++)
    MAP[0][i] =  MAP[i][0] = 0;
```

이렇게 점화식 세울 때 인덱스 안벗어나게 0으로 초기화 해준다.  
**근데 반복을 행의 길이인 r로 했는데 통과했네? 열의 길이가 더 길었다면 `MAP[0][i]` 어딘가에 쓰레기값으로 틀렸을텐데**  
문제조건에 정사각형이 아닌 직사각형이라 했으니 조심하자.

부분합 구할 때 중복되는 부분이 있으므로

```cpp
PSUM[i][j] = PSUM[i-1][j] + PSUM[i][j-1] + PSUM[i][j] + MAP[i][j]
```

위의 사각형과 왼쪽 사각형을 더해준 후 중복되는 사각형 빼주고 현재값 더해주기.

---

마지막에 좌표 주어지고 부분합 출력하려고 합 구할 때 시작점이 (2,2) 로 주어지면 구해야 하는 부분합은 `PSUM[1][1]` 로 시작함. 이거 주의하기

```cpp
#include <bits/stdc++.h>

using namespace std;

int MAP[1025][1025];
int PSUM[1025][1025];
int r, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> MAP[i][j];
        }
    }

    PSUM[0][0] = 0;
    for (int i = 1; i <= r; i++) {
        PSUM[i][0] = PSUM[0][i] = 0;
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            PSUM[i][j] = PSUM[i - 1][j] + PSUM[i][j - 1] + MAP[i][j] - PSUM[i - 1][j - 1];
        }
    }

    cout << '\n';
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++)
            cout << PSUM[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';

    int it;
    cin >> it;

    int row, col;
    pair<int, int> st, end;

    for (int i = 0; i < it; i++) {
        for (int i = 0; i < 2; i++) {
            cin >> row >> col;
            if (!i) {
                st = make_pair(row - 1, col - 1);
            } else {
                end = make_pair(row, col);
            }
        }

        cout << PSUM[end.first][end.second] - PSUM[end.first][st.second] - PSUM[st.first][end.second] + PSUM[st.first][st.second]
             << '\n';
    }
}
```
