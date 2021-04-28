#include <bits/stdc++.h>

using namespace std;

int a[202][202];
queue<pair<int, int>> q;
int SIZE;
int network = 0;
vector<int> VISITED;

void bfs() {
    int row = 1, col = 1;
    VISITED[1] = 1;
    while (1) {
        if (a[row][col] == 1) {
            q.push(make_pair(row, col));
            a[row][col] = a[col][row] = 0;
            VISITED[col] = 1;
            row = col;
            col = 1;
        } else if (col == SIZE) {
            if (q.empty()) {
                network++;
                int flag = 0;
                for (int i = 1; i <= SIZE; i++) {
                    if (VISITED[i] == 0) {
                        VISITED[i] = 1;
                        row = i;
                        col = 1;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    return;
            } else {
                row = q.front().first;
                col = q.front().second;
                q.pop();
            }
        } else {
            col++;
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(a, -1, sizeof(a));
    SIZE = n;
    VISITED.resize(SIZE + 1);

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            a[r][c] = r == c ? 0 : computers[r - 1][c - 1];
        }
    }

    bfs();

    return network;
}