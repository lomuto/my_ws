#include <bits/stdc++.h>
using namespace std;

vector<bool> isVisited;
vector<vector<int>> graph;
vector<vector<int>> graphT;
list<int> postOrder;
unordered_set<int> startingVertex;
vector<vector<int>> scc;

void setPostOrder(int currVertex) {
    isVisited[currVertex] = true;

    for (int adjacentVertex : graph[currVertex]) {
        if (isVisited[adjacentVertex] == false) {
            isVisited[adjacentVertex] = true;
            setPostOrder(adjacentVertex);
        }
    }

    postOrder.push_front(currVertex);
}

void setScc(int currVertex, vector<int> &sccSet) {
    isVisited[currVertex] = true;

    for (int nextVertex : graphT[currVertex]) {
        if (isVisited[nextVertex] == false) {
            isVisited[nextVertex] = true;
            setScc(nextVertex, sccSet);
        }
    }

    sccSet.push_back(currVertex);
}

int main() {
    int vertexCnt;
    int edgeCnt;

    cin >> vertexCnt >> edgeCnt;
    isVisited.resize(vertexCnt + 1);
    graph.resize(vertexCnt + 1);
    graphT.resize(vertexCnt + 1);

    for (int i = 0; i < vertexCnt; i++) {
        startingVertex.insert(i + 1);
    }

    int to, from;
    for (int i = 0; i < edgeCnt; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graphT[to].push_back(from);
        startingVertex.erase(to);
    }

    for (int i = 1; i <= vertexCnt; i++) {
        if (isVisited[i] == false) {
            setPostOrder(i);
        }
    }

    for (int i = 0; i < vertexCnt; i++) {
        isVisited[i + 1] = false;
    }

    for (int i : postOrder) {
        vector<int> sccSet;
        if (isVisited[i] == false) {
            setScc(i, sccSet);
            sort(sccSet.begin(), sccSet.end());
            sccSet.push_back(-1);
            scc.push_back(sccSet);
        }
        // cout << "Scc " << i << '\n';
        // for (int s : sccSet) {
        //     cout << s << ' ';
        // }
        // cout << '\n';
    }
    sort(scc.begin(), scc.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });

    cout << scc.size() << '\n';
    for (vector<int> v : scc) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}