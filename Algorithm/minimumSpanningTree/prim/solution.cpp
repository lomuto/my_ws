#include <bits/stdc++.h>

using namespace std;

int vertexCnt;
int edgeCnt;
int rootOfMst;
unordered_map<int, vector<pair<int, int>>> graph;

/*
    프림알고리즘은 임의의 시작점 노드를 시발점으로 해서
    확장되어 나가는 트리에 인접한 노드들을 검색함.
    고로 kruskal처럼 두개의 disjoint한 tree set이 생성되지 않음!
    따라서 확장되어나가는 유일한 트리(set)를 나타내는 set 하나만 있으면 됨
*/
unordered_set<int> isSubsetOfMst;

struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        /*
            pq는 queue형태라 제일 낮은 index부터 pop
            작은값부터 pop 하고 싶다면 오름차순으로 정렬해야함
            head -> 2 6 9 12 28 67 99 102
        */
        return a.second > b.second;
    }
};

long long getMstWeight() {
    long long ret = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (pair<int, int> &p : graph[rootOfMst]) {
        pq.push(p);
    }
    isSubsetOfMst.insert(rootOfMst);

    while (!pq.empty()) {
        int now = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if (isSubsetOfMst.find(now) != isSubsetOfMst.end()) {
            continue;
        }

        isSubsetOfMst.insert(now);
        ret += weight;
        for (pair<int, int> &p : graph[now]) {
            pq.push(p);
        }
    }

    return ret;
}

int main() {
    cin >> vertexCnt >> edgeCnt;

    isSubsetOfMst.reserve(vertexCnt);

    int src;
    int dest;
    int weight;
    for (int i = 0; i < edgeCnt; i++) {
        cin >> src >> dest >> weight;
        rootOfMst = src;
        /*
            그래프는 양방향...
            해시맵에 src,dest 각각 키값으로 엣지 추가해줘야댐
        */
        graph[src].push_back(pair<int, int>{dest, weight});
        graph[dest].push_back(pair<int, int>{src, weight});
    }

    cout << getMstWeight();
}