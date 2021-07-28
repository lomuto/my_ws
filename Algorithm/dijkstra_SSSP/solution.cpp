#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
vector<map<int, int>> GRAPH;
vector<int> shortestDistance;
vector<int> prevVertex;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(pair<int, int>{0, start});
    shortestDistance[start] = 0;
    prevVertex[start] = start;

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        int currentWeight = p.first;
        int watchingVertex = p.second;
        pq.pop();

        // cout << "from vertex: " << watchingVertex << '\n';

        map<int, int>::iterator it = GRAPH[watchingVertex].begin();
        while (it != GRAPH[watchingVertex].end()) {
            int candidateVertex = it->first;
            int weight = it->second;

            // cout << "to vertex: " << candidateVertex << ", weight: " << weight << '\n';

            if (currentWeight + weight < shortestDistance[candidateVertex]) {
                prevVertex[candidateVertex] = watchingVertex;
                shortestDistance[candidateVertex] = currentWeight + weight;
                pq.push(pair<int, int>{currentWeight + weight, candidateVertex});
            }

            it++;
        }
    }
}

void printPath(int start, int curr) {
    if (curr == start) {
        cout << start << "-> ";
        return;
    }

    printPath(start, prevVertex[curr]);

    cout << curr << "-> ";
}

int main() {
    int v, e;
    cin >> v >> e;
    GRAPH.resize(v + 1);

    shortestDistance.resize(v + 1);
    fill(shortestDistance.begin(), shortestDistance.end(), INF);
    prevVertex.resize(v + 1);

    int start;
    cin >> start;

    int from, to, weight;
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> weight;
        if (GRAPH[from].find(to) != GRAPH[from].end()) {
            if (GRAPH[from][to] > weight) {
                GRAPH[from][to] = weight;
            }
            continue;
        }
        GRAPH[from].insert(pair<int, int>{to, weight});
    }

    dijkstra(start);

    for (int i = 1; i <= v; i++) {
        if (shortestDistance[i] == INF) {
            cout << "INF\n";
            continue;
        }
        cout << shortestDistance[i] << '\n';
    }

    for (int i = 1; i <= v; i++) {
        if (i == start) {
            continue;
        }
        cout << "print Path from " << start << " to " << i << '\n';
        printPath(start, i);
        cout << '\n';
    }
}