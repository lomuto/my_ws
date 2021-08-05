#include <bits/stdc++.h>

using namespace std;

vector<int> verticies;

int findSet(int n) {
    if (verticies[n] == n) {
        return n;
    }

    return findSet(verticies[n]);
}

bool unionSet(int a, int b) {
    int root0 = findSet(a);
    int root1 = findSet(b);

    if (root0 == root1) {
        return false;
    }

    verticies[root1] = root0;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        verticies.push_back(i);
    }

    /*
        최소 스패닝 트리.
        edge들을 오름차순으로 정렬
        유니온 파인드 수행.. 맞나?
    */

    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
        return a[2] < b[2];
    });

    for (vector<int> v : costs) {
        if (unionSet(v[0], v[1])) {
            answer += v[2];
        }
    }

    return answer;
}