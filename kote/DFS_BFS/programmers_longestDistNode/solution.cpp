#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;

int findMaxEdge() {
    int maxDistance = 0;
    int maxDistanceVerticiesCnt = 0;

    queue<pair<int, int>> q;
    vector<bool> isVisited;
    isVisited.resize(graph.size());

    q.push(pair<int, int>{1, 0});
    isVisited[1] = true;

    while (!q.empty()) {
        int currNode = q.front().first;
        int currCnt = q.front().second;
        q.pop();

        for (int nextNode : graph[currNode]) {
            if (isVisited[nextNode]) {
                continue;
            }

            isVisited[nextNode] = true;
            q.push(pair<int, int>{nextNode, currCnt + 1});
            // cout << currNode << " -> " << nextNode << ": " << currCnt + 1 << '\n';

            if (maxDistance < currCnt + 1) {
                maxDistanceVerticiesCnt = 1;
                maxDistance = currCnt + 1;
                continue;
            }
            if (maxDistance == currCnt + 1) {
                maxDistanceVerticiesCnt++;
                continue;
            }
        }
    }

    return maxDistanceVerticiesCnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    graph.resize(n + 1);

    for (int i = 0; i < edge.size(); i++) {
        for (int j = 0; j < edge[i].size(); j += 2) {
            graph[edge[i][j]].push_back(edge[i][j + 1]);
            graph[edge[i][j + 1]].push_back(edge[i][j]);
        }
    }

    // for(int i=1; i<graph.size(); i++) {
    //     cout << i << "~ ";
    //     for(int j=0; j<graph[i].size(); j++) {
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return findMaxEdge();
}