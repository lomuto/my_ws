#include <bits/stdc++.h>

using namespace std;

class Cmp {
  public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.second.second < b.second.second;
    }
};

class Node {
  public:
    int num;
    int x;
    int y;
    Node *left;
    Node *right;
    Node(int, int, int);
    static Node *insert(Node *node, Node *newNode);
    static void preOrder(vector<int> &v, Node *node);
    static void postOrder(vector<int> &v, Node *node);
};

Node::Node(int num, int x, int y)
    : num(num), x(x), y(y) {
    left = nullptr;
    right = nullptr;
}

Node *Node::insert(Node *node, Node *newNode) {
    if (node == nullptr) {
        return newNode;
    }

    if (node->x < newNode->x) {
        node->right = insert(node->right, newNode);
        return node;
    }
    node->left = insert(node->left, newNode);
    return node;
}

void Node::preOrder(vector<int> &v, Node *node) {
    if (node == nullptr) {
        return;
    }

    v.push_back(node->num);
    preOrder(v, node->left);
    preOrder(v, node->right);
}

void Node::postOrder(vector<int> &v, Node *node) {
    if (node == nullptr) {
        return;
    }

    postOrder(v, node->left);
    postOrder(v, node->right);
    v.push_back(node->num);
}

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Cmp> pq;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    answer.resize(2);
    int nodeNum = 1;
    for (int i = 0; i < nodeinfo.size(); i++) {
        for (int j = 0; j < nodeinfo[i].size(); j += 2) {
            int x = nodeinfo[i][j];
            int y = nodeinfo[i][j + 1];

            pq.push(pair<int, pair<int, int>>{nodeNum, {x, y}});
            nodeNum++;
        }
    }

    int num = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();
    Node *rootNode = new Node(num, x, y);

    while (!pq.empty()) {
        num = pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();

        Node *newNode = new Node(num, x, y);

        Node::insert(rootNode, newNode);
    }

    Node::preOrder(answer[0], rootNode);
    Node::postOrder(answer[1], rootNode);

    return answer;
}