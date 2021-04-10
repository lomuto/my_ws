#include <bits/stdc++.h>
using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int MAP[102][102];
int n, m, answer = 10001;

void DFS(int r, int c, int cnt) {
    // cout << "Curr: " << r << ' ' << c << '\n';
    if (r == n && c == m) {
        if (answer > cnt)
            answer = cnt;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if (MAP[next_r][next_c] > 0) {
            if (MAP[next_r][next_c] > cnt) {
                MAP[next_r][next_c] = cnt;
                DFS(next_r, next_c, cnt + 1);
            }
        }
    }
    return;
}

int solution(vector<vector<int>> maps) {
    n = maps.size();
    m = maps[0].size();
    memset(MAP, -1, sizeof(MAP));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (maps[i - 1][j - 1])
                MAP[i][j] = 10001;

    DFS(1, 1, 1);

    return answer == 10001 ? -1 : answer;
}