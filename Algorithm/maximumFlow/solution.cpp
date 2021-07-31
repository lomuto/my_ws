#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<pair<pair<int, int>, int>> outPair;
int vertexCnt;
int srcNode = 0;
int destNode = 5;

void setGraph(int src, int dest, int weight) {
    graph[src][dest] = weight;
    graph[dest][src] = 0; // set backEdge as 0
}

void initGraph() {
    graph.resize(vertexCnt);
    // for (vector<int> &v : graph) {
    //     v.resize(vertexCnt);
    // }
    for (int i = 0; i < vertexCnt; i++) {
        graph[i].resize(vertexCnt);
    }

    setGraph(0, 1, 16);
    setGraph(0, 2, 13);
    setGraph(1, 6, 10);
    setGraph(2, 6, 4);
    setGraph(1, 3, 12);
    setGraph(3, 2, 9);
    setGraph(2, 4, 14);
    setGraph(4, 3, 7);
    setGraph(4, 5, 4);
    outPair.push_back(pair<pair<int, int>, int>{{4, 5}, 4});
    setGraph(3, 5, 20);
    outPair.push_back(pair<pair<int, int>, int>{{3, 5}, 20});
}

bool bfs(vector<int> &path) {
    queue<int> q;
    q.push(srcNode);

    vector<bool> isDiscovered;
    isDiscovered.resize(vertexCnt);

    isDiscovered[srcNode] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == destNode) {
            return true;
        }

        for (int next = 0; next < vertexCnt; next++) {
            if (graph[curr][next] == 0 || isDiscovered[next]) {
                continue;
            }

            isDiscovered[next] = true;
            path[next] = curr;
            q.push(next);
        }
    }

    return false;
}

void getPath(int currNode, deque<int> &path, const vector<int> &sequence) {
    path.push_front(currNode);

    if (currNode == srcNode) {
        return;
    }

    getPath(sequence[currNode], path, sequence);
}

int getMaxFlow(const deque<int> &path) {
    int maxFlow = graph[path[0]][path[1]];
    for (int i = 1; i < path.size() - 1; i++) {
        maxFlow = min(maxFlow, graph[path[i]][path[i + 1]]);
    }
    return maxFlow;
}

void setFlow(const deque<int> &path, int maxFlow) {
    for (int i = 0; i < path.size() - 1; i++) {
        graph[path[i]][path[i + 1]] -= maxFlow;
        graph[path[i + 1]][path[i]] += maxFlow;
    }
}

void edmondKarp() {
    while (1) {
        vector<int> sequence;
        deque<int> path;
        sequence.resize(vertexCnt);
        if (!bfs(sequence)) {
            return;
        }

        getPath(destNode, path, sequence);
        // for (int i : path) {
        //     cout << i << ' ';
        // }
        // cout << '\n';
        int maxFlow = getMaxFlow(path);
        // cout << "maxFlow: " << maxFlow << '\n';
        setFlow(path, maxFlow);
    }
}

int main() {
    vertexCnt = 6 + 1; // 1 for ghost node
    initGraph();
    edmondKarp();

    cout << graph[3][destNode] << ',' << graph[4][destNode] << '\n';
    for (pair<pair<int, int>, int> p : outPair) {
        cout << p.second - graph[p.first.first][p.first.second] << '\n';
    }
}