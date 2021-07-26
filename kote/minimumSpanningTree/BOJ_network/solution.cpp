#include <bits/stdc++.h>
using namespace std;

int *verticies;

vector<pair<pair<int, int>, int>> edges;

int findSet(int vertex) {
    if (verticies[vertex] == vertex) {
        return vertex;
    }

    verticies[vertex] = findSet(verticies[vertex]);
    return verticies[vertex];
}

void unionSet(int vertex0, int vertex1) {
    if (findSet(vertex0) == findSet(vertex1)) {
        return;
    }

    verticies[findSet(vertex1)] = findSet(vertex0);

    // 밑에처럼 루트를 받아서 넘겨주던가
    // vertex0 = findSet(vertex0);
    // vertex1 = findSet(vertex1);
    // if (vertex0 == vertex1) {
    //     return;
    // }

    // verticies[vertex1] = vertex0;
}

int mst() {
    int sum = 0;
    for (pair<pair<int, int>, int> edge : edges) {
        int vertex0 = edge.first.first;
        int vertex1 = edge.first.second;

        if (vertex0 == vertex1 || findSet(vertex0) == findSet(vertex1)) {
            continue;
        }

        unionSet(vertex0, vertex1);
        sum += edge.second;
    }

    return sum;
}

int main() {
    int vertexCnt;
    int edgeCnt;

    cin >> vertexCnt >> edgeCnt;
    verticies = new int[vertexCnt + 1];

    for (int i = 0; i < vertexCnt; i++) {
        verticies[i + 1] = i + 1;
    }

    int vertex0;
    int vertex1;
    int weight;

    for (int i = 0; i < edgeCnt; i++) {
        cin >> vertex0 >> vertex1 >> weight;
        edges.push_back(pair<pair<int, int>, int>{{vertex0, vertex1}, weight});
    }

    sort(edges.begin(), edges.end(), [](pair<pair<int, int>, int> edge0, pair<pair<int, int>, int> edge1) {
        return edge0.second < edge1.second;
    });

    cout << mst() << '\n';
}