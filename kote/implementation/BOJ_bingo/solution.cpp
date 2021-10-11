#include <bits/stdc++.h>

using namespace std;

const int SIZE = 5;

vector<vector<int>> v;
unordered_map<int, pair<int, int>> coordinateByNumber;

int dr[] = {1, 0, 1, 1};
int dc[] = {0, -1, -1, 1};

bool isMoveValid(int r, int c) {
    return r >= 0 && c >= 0 && r < SIZE && c < SIZE;
}

int getBingoCount(int r, int c) {
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int bingoCount = 0;
        int currR = r;
        int currC = c;

        bool isBingo = false;
        while (isMoveValid(currR, currC)) {
            if (!v[currR][currC]) {
                bingoCount++;
            } else {
                break;
            }
            if (bingoCount == SIZE) {
                ret++;
                isBingo = true;
                break;
            }
            currR += dr[i];
            currC += dc[i];
        }

        if (isBingo) {
            continue;
        }

        currR = r - dr[i];
        currC = c - dc[i];

        while (isMoveValid(currR, currC)) {
            if (!v[currR][currC]) {
                bingoCount++;
            } else {
                break;
            }
            if (bingoCount == SIZE) {
                ret++;
                break;
            }
            currR -= dr[i];
            currC -= dc[i];
        }
    }
    return ret;
}

int main() {
    v.resize(SIZE);
    for (int i = 0; i < SIZE; i++) {
        v[i].resize(SIZE);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> v[i][j];
            coordinateByNumber.insert(pair<int, pair<int, int>>{v[i][j], pair<int, int>{i, j}});
        }
    }

    int input;
    int buf;
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> input;
            pair<int, int> coordinate = coordinateByNumber[input];
            v[coordinate.first][coordinate.second] = 0;
            if (buf = getBingoCount(coordinate.first, coordinate.second)) {
                count += buf;
            }
            if (count >= 3) {
                cout << i * SIZE + j + 1 << '\n';
                return 0;
            }
        }
    }
}
