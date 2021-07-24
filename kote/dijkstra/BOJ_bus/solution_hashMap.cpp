#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
vector<unordered_map<int, int>> bus;
vector<int> distances;
int vertexCnt;
int edgeCnt;

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[src] = 0;
    pq.push(pair<int, int>{0, src});

    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        int distanceToCurrentVertex = pq.top().first;
        pq.pop();

        for (pair<int, int> adjacent : bus[currentVertex]) {
            int candidateVertex = adjacent.first;
            int weightOfCandidateVertex = adjacent.second;

            if (distances[candidateVertex] > weightOfCandidateVertex + distanceToCurrentVertex) {
                distances[candidateVertex] = weightOfCandidateVertex + distanceToCurrentVertex;
                pq.push(pair<int, int>{distances[candidateVertex], candidateVertex});
            }
        }
    }
}

int main() {
    cin >> vertexCnt >> edgeCnt;
    distances.resize(vertexCnt + 1, INF);
    bus.resize(vertexCnt + 1);

    int from, to, weight;
    for (int i = 0; i < edgeCnt; i++) {
        cin >> from >> to >> weight;
        if (bus[from].find(to) != bus[from].end()) {
            if (bus[from][to] > weight) {
                bus[from][to] = weight;
            }
            continue;
        }
        bus[from].insert(pair<int, int>{to, weight});
    }

    int src, dest;
    cin >> src >> dest;
    dijkstra(src);

    cout << distances[dest] << '\n';
}