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

### 2. stack STL 사용 시 seg fault 발생했음. 이유 모름. 그냥 벡터 쓰자

<br/>   
   
지금 로컬에서는 잘 돌아가는데 제출만하면 런타임났다고함. 해결되면 업데이트

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ROW, COL;
    pair<int, int> COOR;

    vector<pair<int, int>> v;

    cin >> ROW >> COL;

    int **MAP = new int *[ROW];
    for (int _ = 0; _ < ROW; _++)
        MAP[_] = new int[ROW];

    string buf;
    for (int i = 0; i < ROW; i++) {
        cin >> buf;
        for (int j = 0; j < COL; j++) {
            buf[j] - '0' ? MAP[i][j] = 0 : MAP[i][j] = 1;
        }
    }

    for (int r = 0, c = 0; c < COL; c++) {
        if (MAP[r][c]) {
            while (1) {
                if (r == ROW - 1) {
                    cout << "YES";
                    return 0;
                }

                MAP[r][c] = false; // visited

                if (r < ROW - 1 && MAP[r + 1][c]) {
                    v.push_back(make_pair(r, c));
                    r++;
                } else if (c < COL - 1 && MAP[r][c + 1]) {
                    v.push_back(make_pair(r, c));
                    c++;
                } else if (r > 0 && MAP[r - 1][c]) {
                    v.push_back(make_pair(r, c));
                    r--;
                } else if (c > 0 && MAP[r][c - 1]) {
                    v.push_back(make_pair(r, c));
                    c--;
                } else {
                    if (v.empty()) {
                        break;
                    }
                    pair<int, int> tmp = v.back();
                    r = tmp.first;
                    c = tmp.second;
                    v.pop_back();
                }
            }
        }
    }
    cout << "NO";

    // for(int _=0; _<ROW; _++)
    //  delete[] MAP[_];
    // delete[] MAP;
}
```
