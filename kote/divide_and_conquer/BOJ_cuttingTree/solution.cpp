#include <bits/stdc++.h>

using namespace std;

long long treeCnt;
long long requriedWood;
vector<long long> trees;

long long maxTreeHeight = 0;

long long getSumOfWood(long long h) {
    long long sum = 0;
    for (long long i : trees) {
        if (i > h)
            sum += (i - h);
    }

    return sum;
}

long long bSearch(long long left, long long right) {
    if (left > right) {
        return right;
    }

    long long mid = (left + right) / 2;
    long long temp = getSumOfWood(mid);

    if (temp == requriedWood) {
        return mid;
    }

    if (temp > requriedWood) {
        return bSearch(mid + 1, right);
    }

    return bSearch(left, mid - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> treeCnt >> requriedWood;
    trees.resize(treeCnt);

    for (long long i = 0; i < treeCnt; i++) {
        cin >> trees[i];
        maxTreeHeight = max(maxTreeHeight, trees[i]);
    }

    cout << bSearch(0, maxTreeHeight) << '\n';
    return 0;
}
