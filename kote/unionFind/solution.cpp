#include <bits/stdc++.h>

using namespace std;

int peopleCnt;
int partyCnt;
vector<pair<int, bool>> peopleSet; //pair<parent, isLiar>
vector<vector<int>> parties;

int findSet(int i) {
    if (peopleSet[i].first == i) {
        return i;
    }

    return findSet(peopleSet[i].first);
}

void unionSet(int a, int b) {
    int rootA = findSet(a);
    int rootB = findSet(b);

    if (rootA == rootB) {
        return;
    }

    peopleSet[rootB].first = rootA;
    peopleSet[rootA].second = peopleSet[rootA].second | peopleSet[rootB].second;
}

int main() {
    cin >> peopleCnt >> partyCnt;
    peopleSet.push_back(pair<int, int>{0, false});
    for (int i = 1; i < peopleCnt + 1; i++) {
        peopleSet.push_back(pair<int, int>{i, false});
    }
    parties.resize(partyCnt);

    int knowsTruthCnt;
    int attendence;
    int attendenceCnt;
    int input;

    cin >> knowsTruthCnt;
    for (int i = 0; i < knowsTruthCnt; i++) {
        cin >> input;
        peopleSet[input].second = true;
    }

    for (int i = 0; i < partyCnt; i++) {
        cin >> attendenceCnt;
        for (int j = 0; j < attendenceCnt; j++) {
            cin >> attendence;
            parties[i].push_back(attendence);
        }
        if (attendenceCnt < 2) {
            continue;
        }
        vector<int> v = parties[i];
        for (int i = 0; i < attendenceCnt - 1; i++) {
            for (int j = i + 1; j < attendenceCnt; j++) {
                unionSet(v[i], v[j]);
            }
        }
    }

    int cnt = 0;
    for (vector<int> v : parties) {
        bool flag = false;
        for (int i : v) {
            if (peopleSet[findSet(i)].second) {
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        cnt++;
    }

    // for (pair<int, int> p : peopleSet) {
    //     cout << p.first << ',' << p.second << ' ';
    // }
    // cout << '\n';

    cout << cnt << '\n';
}