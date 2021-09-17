#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int parent;
    // int size;
    Node(int parent);
};

Node::Node(int parent)
    : parent(parent) {
}

class Edge {
  public:
    int node0;
    int node1;
    int weight;
    Edge(int node0, int node1, int weight);
};

Edge::Edge(int node0, int node1, int weight)
    : node0(node0), node1(node1), weight(weight) {
}

class disjointSet {
  public:
    unordered_map<int, Node *> nodeSet;
    int findSet(int node);
    void unionSet(int node0, int node1);
};

int disjointSet::findSet(int node) {
    // cout << "Finding node " << node << '\n';
    assert(nodeSet.find(node) != nodeSet.end());
    Node *n = nodeSet[node];

    if (n->parent == node) {
        return node;
    }

    n->parent = findSet(n->parent);
    return n->parent;
}

void disjointSet::unionSet(int node0, int node1) {
    assert(nodeSet.find(node0) != nodeSet.end());
    assert(nodeSet.find(node1) != nodeSet.end());

    int root0 = findSet(node0);
    int root1 = findSet(node1);

    if (root0 == root1) {
        return;
    }

    nodeSet[root0]->parent = nodeSet[root1]->parent;
}

vector<Edge *> edges;

void mst(disjointSet &set, vector<Edge *> &path) {
    for (Edge *edge : edges) {
        int node0 = edge->node0;
        int node1 = edge->node1;

        if (set.findSet(node0) == set.findSet(node1)) {
            continue;
        }

        set.unionSet(node0, node1);
        path.push_back(edge);
    }
}

int main() {
    disjointSet set;

    int vertexCnt;
    int edgeCnt;

    cin >> vertexCnt >> edgeCnt;

    for (int i = 0; i < vertexCnt; i++) {
        set.nodeSet.insert(pair<int, Node *>{i + 1, new Node(i + 1)});
    }

    int node0;
    int node1;
    int weight;
    for (int i = 0; i < edgeCnt; i++) {
        cin >> node0 >> node1 >> weight;
        edges.push_back(new Edge(node0, node1, weight));
    }

    sort(edges.begin(), edges.end(), [](const Edge *edge0, const Edge *edge1) {
        return edge0->weight < edge1->weight;
    });

    vector<Edge *> path;
    mst(set, path);

    int answer = 0;
    for (Edge *edge : path) {
        answer += edge->weight;
    }

    cout << answer << '\n';
}