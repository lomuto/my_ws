#include <bits/stdc++.h>
using namespace std;

// const int INF = 1000000000;
// vector<vector<int>> GRAPH;
// vector<int> shortestDistance;

// void dijkstra(int start) {
//     priority_queue<int, vector<int>, greater<int>> pq;

// }

// int main() {
//     int v, e;
//     cin >> v >> e;
//     GRAPH.resize(v);
//     for (int i = 0; i < v; i++) {
//         GRAPH[i].resize(v);
//     }

//     shortestDistance.resize(v);
//     fill(shortestDistance.begin(), shortestDistance.end(), INF);

//     int start;
//     cin >> start;

//     int from, to, weight;
//     for (int i = 0; i < e; i++) {
//         cin >> from >> to >> weight;
//         if (GRAPH[from][to] != 0) {
//             GRAPH[from][to] = min(GRAPH[from][to], weight);
//             continue;
//         }
//         GRAPH[from][to] = weight;
//     }

//     dijkstra(start);
// }

class Node {
  public:
    int data;
    int invertedDepth;
    vector<Node *> next;
    Node(int data);
    static unordered_set<int> isVisited;
    static int setDistanceFromLeafNode(Node *node);
    static void getMinimumDelivery(Node *node, int &count, int power);
};

Node::Node(int data)
    : data(data) {
    invertedDepth = 0;
}

unordered_set<int> Node::isVisited;

int Node::setDistanceFromLeafNode(Node *node) {
    isVisited.insert(node->data);
    if (node->next.size() == 1 && isVisited.find(node->next[0]->data) != isVisited.end()) {
        node->invertedDepth = 1;
        return node->invertedDepth;
    }

    for (Node *nextNode : node->next) {
        if (isVisited.find(nextNode->data) == isVisited.end())
            node->invertedDepth = max(node->invertedDepth, setDistanceFromLeafNode(nextNode) + 1);
    }

    return node->invertedDepth;
}

void Node::getMinimumDelivery(Node *node, int &count, int power) {
    isVisited.insert(node->data);
    if (node->invertedDepth > power) {
        count++;
    }
    for (Node *nextNode : node->next) {
        if (isVisited.find(nextNode->data) == isVisited.end())
            getMinimumDelivery(nextNode, count, power);
    }
}

int main() {
    int n, start, power;
    cin >> n >> start >> power;

    // n이 1이면 반복문 실행 안돼서 예ㅔ외처리
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    unordered_map<int, Node *> nodeByData;

    int from, to;
    Node *fromNode, *toNode;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;
        if (nodeByData.find(from) == nodeByData.end()) {
            nodeByData.insert(pair<int, Node *>{from, new Node(from)});
        }
        fromNode = nodeByData[from];
        if (nodeByData.find(to) == nodeByData.end()) {
            nodeByData.insert(pair<int, Node *>{to, new Node(to)});
        }
        toNode = nodeByData[to];

        fromNode->next.push_back(toNode);
        toNode->next.push_back(fromNode);
    }

    Node::setDistanceFromLeafNode(nodeByData[start]);
    int count = 0;

    Node::isVisited.clear();
    Node::getMinimumDelivery(nodeByData[start], count, power);
    // count가 0이면 출력 시 음수가 나올 수 있음. 예외처리
    // count에서 자기 자신을 세느라 그거 빼면서 생긴 문제.
    if (count == 0) {
        cout << 0 << '\n';
        return 0;
    }
    cout << (count - 1) * 2;
}