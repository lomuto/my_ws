#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> MAP;
vector<vector<int>> grid;
int row, col;

int solution(int m, int n, vector<vector<int>> puddles) {
    row = n;
    col = m;

    MAP.resize(n);
    grid.resize(n);
    for (vector<int> &v : MAP) {
        v.resize(m);
    }
    for (vector<int> &v : grid) {
        v.resize(m);
    }

    for (int i = 0; i < puddles.size(); i++) {
        for (int j = 0; j < puddles[i].size(); j += 2) {
            int c = puddles[i][j] - 1;
            int r = puddles[i][j + 1] - 1;
            MAP[r][c] = -1;
        }
    }

    for (int i = 0; i < row; i++) {
        if (MAP[i][0] == -1) {
            break;
        }
        grid[i][0] = 1;
    }
    for (int i = 0; i < col; i++) {
        if (MAP[0][i] == -1) {
            break;
        }
        grid[0][i] = 1;
    }

    for (int r = 1; r < row; r++) {
        for (int c = 1; c < col; c++) {
            if (MAP[r][c] == -1) {
                continue;
            }
            grid[r][c] = (grid[r - 1][c] + grid[r][c - 1]) % 1000000007;
        }
    }

    return grid[n - 1][m - 1];
}