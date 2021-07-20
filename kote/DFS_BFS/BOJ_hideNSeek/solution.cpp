#include <bits/stdc++.h>
using namespace std;

int movement(int curr, int n) {
    switch (n) {
    case 0:
        return curr + 1;
    case 1:
        return curr - 1;
    case 2:
        return curr * 2;
    }
}

bool isValidMove(int location) {
    return location >= 0 && location <= 100000;
}

int bfs(int location, int destination) {
    pair<int, int> curr;
    queue<pair<int, int>> q;
    unordered_set<int> isVisited;

    q.push(pair<int, int>{location, 0});
    isVisited.insert(location);
    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (destination == curr.first) {
            return curr.second;
        }

        for (int i = 0; i < 3; i++) {
            int nextMove = movement(curr.first, i);
            if (isValidMove(nextMove) && isVisited.find(nextMove) == isVisited.end()) {
                q.push(pair<int, int>{nextMove, curr.second + 1});
                isVisited.insert(nextMove);
            }
        }
    }
}

int main() {
    // ios_base ::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int start, destination;
    cin >> start >> destination;

    cout << bfs(start, destination) << '\n';
}