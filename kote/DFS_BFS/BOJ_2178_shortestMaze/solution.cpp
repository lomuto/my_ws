#include <bits/stdc++.h>

using namespace std;

int MAP[102][102];
bool V[102][102] = {
    0,
};
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void BFS() {
    int r = 1, c = 1;
    q.push(make_pair(r, c));
    V[r][c] = 1;

    while (!(q.empty())) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        int next_r, next_c;
        for (int i = 0; i < 4; i++) {
            next_r = r + dr[i];
            next_c = c + dc[i];
            if (V[next_r][next_c] == 0 && MAP[next_r][next_c] > 0) {
                q.push(make_pair(next_r, next_c));
                V[next_r][next_c] = 1;
                MAP[next_r][next_c] = MAP[r][c] + 1;
            }
        }
    }

    return;
}

int main() {
    int r, c;
    memset(MAP, -1, sizeof(MAP));
    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        string buf;
        cin >> buf;
        for (int j = 1; j <= c; j++) {
            MAP[i][j] = buf[j - 1] - '0';
        }
    }

    BFS();

    cout << MAP[r][c];
}