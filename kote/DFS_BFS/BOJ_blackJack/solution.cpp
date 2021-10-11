#include <bits/stdc++.h>

using namespace std;

int cardCnt;
int target;
vector<int> v;
vector<int> isVisited;
int answer = 0;

void dfs(int count, int sum) {
    if (count == 3 && sum <= target) {
        answer = max(sum, answer);
        return;
    }

    if (sum > target || count >= 3) {
        return;
    }

    for (int i = 0; i < cardCnt; i++) {
        if (isVisited[i] == false) {
            isVisited[i] = true;
            dfs(count + 1, sum + v[i]);
            isVisited[i] = false;
        }
    }
}

int main() {
    cin >> cardCnt >> target;
    v.resize(cardCnt);
    isVisited.resize(cardCnt);

    for (int i = 0; i < cardCnt; i++) {
        cin >> v[i];
    }

    dfs(0, 0);

    cout << answer << '\n';
}
