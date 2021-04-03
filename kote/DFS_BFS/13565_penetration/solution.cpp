#include <bits/stdc++.h>
using namespace std;

int MAP[1010][1010];
queue<pair<int, int>> q;
int r, c;
int ans = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void BFS(int x, int y) {

    MAP[x][y] = 1; // visit
    if (x == r) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (MAP[x + dx[i]][y + dy[i]] == 0)
            BFS(x + dx[i], y + dy[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(MAP, -1, sizeof(MAP));

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        string buf;
        cin >> buf;
        for (int j = 1; j <= c; j++)
            MAP[i][j] = buf[j - 1] - '0';
    }
    for (int i = 1; i <= c; i++)
        if (MAP[1][i] == 0)
            BFS(1, i);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
}