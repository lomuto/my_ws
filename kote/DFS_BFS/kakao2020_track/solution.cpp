#include <bits/stdc++.h>
#define newPair(weight, y, x, moveY, moveX)           \
    pair<int, pair<pair<int, int>, pair<int, int>>> { \
        (weight), {                                   \
            {(y), (x)}, { (moveY), (moveX) }          \
        }                                             \
    }

using namespace std;

vector<vector<bool>> track;
vector<vector<int>> priceBoard;
int rowSize;
int colSize;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool isMoveValid(int r, int c) {
    if (r < 0 || r > rowSize - 1 || c < 0 || c > colSize - 1) {
        return false;
    }
    return !track[r][c];
}

void bfs() {
    track[0][0] = 1;
    queue<pair<int, pair<pair<int, int>, pair<int, int>>>> q;
    if (!track[0][1]) {
        q.push(newPair(100, 0, 1, 0, 1));
        track[0][1] = 1;
        priceBoard[0][1] = 100;
    }
    if (!track[1][0]) {
        q.push(newPair(100, 1, 0, 1, 0));
        track[1][0] = 1;
        priceBoard[1][0] = 100;
    }

    while (!q.empty()) {
        int currWeight = q.front().first;
        int currR = q.front().second.first.first;
        int currC = q.front().second.first.second;
        int prevMoveY = q.front().second.second.first;
        int prevMoveX = q.front().second.second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = currR + dr[i];
            int nextC = currC + dc[i];
            if (isMoveValid(nextR, nextC)) {
                int nextWeight = currWeight + 100;
                if (prevMoveY ^ dr[i] && prevMoveX ^ dc[i]) {
                    nextWeight += 500;
                }
                if (priceBoard[nextR][nextC] > nextWeight) {
                    // 최소거리로 업데이트 되는 경우만 push
                    priceBoard[nextR][nextC] = nextWeight;
                    q.push(newPair(nextWeight, nextR, nextC, dr[i], dc[i]));
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    rowSize = board.size();
    colSize = board[0].size();
    priceBoard.resize(rowSize);
    track.resize(rowSize);
    for (int r = 0; r < rowSize; r++) {
        track[r].resize(colSize);
        for (int c = 0; c < colSize; c++) {
            track[r][c] = board[r][c];
        }
    }
    for (vector<int> &v : priceBoard) {
        v.resize(colSize, 100000000);
    }
    bfs();

    for (vector<int> v : priceBoard) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return priceBoard[rowSize - 1][colSize - 1];
}

int main() {
    vector<vector<int>> board1 = {{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}};
    cout << solution(board1) << '\n';
}