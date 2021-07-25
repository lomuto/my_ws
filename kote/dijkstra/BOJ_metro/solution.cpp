#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

vector<vector<pair<int, int>>> metro;
vector<int> stationCompany;
vector<int> dist;
vector<int> previousVertex;

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push(pair<int, int>{dist[src], src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        // cout << "DEBUG\n"
        //      << "u: " << u << " currDist: " << currentDist << '\n';

        if (dist[u] < currentDist) {
            continue;
        }

        for (pair<int, int> adjacent : metro[u]) {
            int v = adjacent.first;
            int adjacentWeight = adjacent.second;

            // cout << "WAtching v: " << v << " weight: " << adjacentWeight << '\n';

            if (dist[v] > currentDist + adjacentWeight) {
                dist[v] = currentDist + adjacentWeight;
                previousVertex[v] = u;
                pq.push(pair<int, int>{dist[v], v});
            }
        }
    }
}

int getTransferCnt(int src, int curr, int transferCnt) {
    if (curr == src) {
        return transferCnt;
    }

    int previous = previousVertex[curr];

    if (stationCompany[curr] != stationCompany[previous]) {
        transferCnt++;
    }

    return getTransferCnt(src, previous, transferCnt);
}

int main() {
    int stationCnt;
    int destination;
    int src = 0;

    cin >> stationCnt >> destination;

    metro.resize(stationCnt);
    stationCompany.resize(stationCnt);
    dist.resize(stationCnt, INF);
    previousVertex.resize(stationCnt);

    for (int i = 0; i < stationCnt; i++) {
        cin >> stationCompany[i];
    }

    int weight;
    for (int i = 0; i < stationCnt; i++) {
        for (int j = 0; j < stationCnt; j++) {
            cin >> weight;
            if (weight == 0) {
                continue;
            }

            if (stationCompany[i] == stationCompany[j]) {
                metro[i].push_back(pair<int, int>{j, weight});
                continue;
            }

            metro[i].push_back(pair<int, int>{j, weight + 10000000});
        }
    }

    dijkstra(src);

    cout << getTransferCnt(src, destination, 0) << ' ' << dist[destination] % 1000000 << '\n';
}