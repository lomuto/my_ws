#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    grid.resize(n);

    for (int i = 0; i < n; i++) {
        int buf;
        for (int j = 0; j < n; j++) {
            cin >> buf;
            grid[i].push_back(buf);
        }
    }

    for (int i = 0; i < n; i++) {

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                grid[r][c] = grid[r][c] | (grid[r][i] & grid[i][c]);
            }
        }
    }

    for (vector<int> v : grid) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}