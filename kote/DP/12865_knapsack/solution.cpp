#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> GRID;
vector<pair<int, int>> ITEM;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        vector<int> temp;
        temp.resize(col + 1);
        GRID.push_back(temp);
    }

    int weight;
    int value;
    for (int i = 0; i < row; i++) {
        cin >> weight >> value;
        ITEM.push_back(pair<int, int>{weight, value});
    }

    for (int i = 1; i <= col; i++) {
        if (ITEM[0].first <= i) {
            GRID[0][i] = ITEM[0].second;
        }
    }

    for (int currItemIdx = 1; currItemIdx < row; currItemIdx++) {
        pair<int, int> currItem = ITEM[currItemIdx];
        int currWeight = currItem.first;
        int currValue = currItem.second;

        for (int weight = 1; weight <= col; weight++) {
            GRID[currItemIdx][weight] = GRID[currItemIdx - 1][weight];
            if (currWeight == weight) {
                if (GRID[currItemIdx - 1][weight] < currValue) {
                    GRID[currItemIdx][weight] = currValue;
                }
            } else if (currWeight < weight) {
                if (GRID[currItemIdx - 1][weight] < currValue + GRID[currItemIdx - 1][weight - currWeight]) {
                    GRID[currItemIdx][weight] = currValue + GRID[currItemIdx - 1][weight - currWeight];
                }
            }
        }
    }

    // for (vector<int> v : GRID) {
    //     for (int i : v) {
    //         cout << i << " ";
    //     }
    //     cout << '\n';
    // }
    cout << GRID[row - 1][col];
}