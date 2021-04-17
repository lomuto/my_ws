#include <bits/stdc++.h>

using namespace std;

int MAP[102][102];
int VISITED[102][102];
int segment;
int dr[4], dc[4];
int R, C;
int MAX;

void BFS(int r, int c) {
    segment++;

    queue<pair<int, int>> q;
    VISITED[r][c] = 1;
    q.push(make_pair(r, c));
    int cnt = 1;
    while (!(q.empty())) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_r = dr[i] + r;
            int next_c = dc[i] + c;
            if (MAP[next_r][next_c] > 0 && !VISITED[next_r][next_c]) {
                if (MAP[next_r][next_c] == MAP[r][c]) {
                    q.push(make_pair(next_r, next_c));
                    VISITED[next_r][next_c] = 1;
                    cnt++;
                }
            }
        }
    }
    cout << "cnt: " << cnt << '\n';
    MAX = max(MAX, cnt);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area;
    int max_size_of_one_area;
    segment = 0;
    R = m;
    MAX = 0;
    C = n;
    memset(MAP, -1, sizeof(MAP));
    memset(VISITED, 0, sizeof(VISITED));
    dr[0] = 1;
    dr[1] = 0;
    dr[2] = -1;
    dr[3] = 0;
    dc[0] = 0;
    dc[1] = 1;
    dc[2] = 0;
    dc[3] = -1;

    for (int r = 1; r <= m; r++) {
        for (int c = 1; c <= n; c++) {
            MAP[r][c] = picture[r - 1][c - 1];
        }
    }

    for (int r = 1; r <= m; r++) {
        for (int c = 1; c <= n; c++) {
            cout << MAP[r][c];
        }
        cout << '\n';
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!VISITED[i][j] && MAP[i][j] > 0)
                BFS(i, j);
        }
    }

    vector<int> answer(2);
    answer[0] = segment;
    answer[1] = MAX;
    return answer;
}