#include <bits/stdc++.h>
using namespace std;

const int vertexCnt = 4;
const int INF = 1000000000;
vector<unordered_map<int, int>> graph;
vector<vector<int>> grid;

void setGraph() {
    /*
        1
   [0]----[1]
     \     |
      \    |
     6 \   | 3
        \  | 
         \ |
   [3]----[2] 
        5
    */
    graph.resize(vertexCnt);
    graph[0].insert(pair<int, int>{1, 1});
    graph[0].insert(pair<int, int>{2, 6});
    graph[1].insert(pair<int, int>{0, 1});
    graph[1].insert(pair<int, int>{2, 3});
    graph[2].insert(pair<int, int>{0, 6});
    graph[2].insert(pair<int, int>{3, 5});
    graph[2].insert(pair<int, int>{1, 3});
    graph[3].insert(pair<int, int>{2, 5});
}

void initGrid() {
    grid.resize(vertexCnt);

    for (int src = 0; src < vertexCnt; src++) {
        for (int dest = 0; dest < vertexCnt; dest++) {
            if (src == dest) {
                grid[src].push_back(0);
                continue;
            }
            if (graph[src].find(dest) != graph[src].end()) {
                grid[src].push_back(graph[src][dest]);
                continue;
            }
            grid[src].push_back(INF);
        }
    }
}

void floydWarshel() {
    initGrid();

    for (int wayPoint = 1; wayPoint < vertexCnt; wayPoint++) {
        for (int src = 0; src < vertexCnt; src++) {
            for (int dest = 0; dest < vertexCnt; dest++) {
                grid[src][dest] = min(grid[src][dest], grid[src][wayPoint] + grid[wayPoint][dest]);
            }
        }
    }
}

void showGrid() {
    for (vector<int> v : grid) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main() {
    setGraph();
    floydWarshel();
    showGrid();
}