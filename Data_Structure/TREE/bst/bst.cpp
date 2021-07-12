#include <bits/stdc++.h>

using namespace std;

/*************************************************/
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node();
    Node(int v);
};

Node::Node()
    : Node(-1) {}

Node::Node(int v)
    : data(v), left(nullptr), right(nullptr) {}

/*************************************************/

class BST {
  public:
    Node *HEAD;
    int height;
    queue<int> ELEMENTS;
    BST();
    void INSERT(int v);
    void ERASE(int v);
    void DFS_COUNT_HEIGHT(const Node *ptr, int n);
    void FILL_ELEMENT();
    void SHOW_ME_THE_TREE();
    void INORDER();
    static int LEAF_CNT(int n);
};

BST::BST() : HEAD(nullptr), height(0) {}

void BST::INSERT(int v) {
    Node *newNode = new Node(v);

    if (HEAD == nullptr) {
        HEAD = newNode;
        return;
    }

    Node *ptr = HEAD;
    while (ptr != nullptr) {
        if (ptr->data < v) {
            if (ptr->right == nullptr) {
                ptr->right = newNode;
                return;
            } else
                ptr = ptr->right;
        } else if (ptr->data > v) {
            if (ptr->left == nullptr) {
                ptr->left = newNode;
                return;
            } else
                ptr = ptr->left;
        } else {
            cerr << "Same Data\n";
            return;
        }
    }
}

void BST::ERASE(int v) {
    if (HEAD == nullptr) {
        cerr << "Emtpy Tree\n";
        return;
    }

    Node *ptr = HEAD;
    while (ptr->data != v) {
        if (ptr == nullptr) {
            cerr << "No such node with given argument\n";
            return;
        }

        if (ptr->data < v)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }

    Node *temp = ptr;
    if (temp->left != nullptr) {
        temp = ptr->left;
        temp->right = ptr->right;
        delete ptr;
    } else if (temp->right != nullptr) {
        temp = ptr->right;
        temp->left = ptr->left;
        delete ptr;
    } else
        delete ptr;
}

void BST::DFS_COUNT_HEIGHT(const Node *ptr, int n) {
    cout << "n: " << n << '\n';
    if (ptr == nullptr) {
        height = max(n, height);
        return;
    }

    DFS_COUNT_HEIGHT(ptr->left, n + 1);
    DFS_COUNT_HEIGHT(ptr->right, n + 1);
}

void BST::FILL_ELEMENT() {
    queue<Node *> nodeq;
    nodeq.push(HEAD);

    Node *n;
    while (!nodeq.empty()) {
        n = nodeq.front();
        nodeq.pop();

        if (n == nullptr)
            ELEMENTS.push(-1);
        else
            ELEMENTS.push(n->data);

        if (n != nullptr) {
            nodeq.push(n->right);
            nodeq.push(n->left);
        }
    }
    cout << "DEBUG fill queue size:" << ELEMENTS.size() << '\n';
}

void BST::SHOW_ME_THE_TREE() {
    DFS_COUNT_HEIGHT(HEAD, 0);
    FILL_ELEMENT();
    cout << "\n HEIGHT: " << height << '\n';
    int width = LEAF_CNT(height);
    for (int i = 0; i <= height; i++) {
        for (int k = 0; k < pow(2, i); k++) {
            cout << ELEMENTS.front() << ' ';
            ELEMENTS.pop();
        }
        cout << '\n';
    }
}

int BST::LEAF_CNT(int n) {
    if (n <= 0)
        return 1;

    return (LEAF_CNT(n - 1)) * 2 + 1;
}

void INORDER(const Node *n) {
    if (n == nullptr)
        return;

    INORDER(n->left);
    cout << n->data << ' ';
    INORDER(n->right);
}

int main() {
    BST t;
    for (int i = 0; i < 5; i++)
        t.INSERT(rand() % 100 + 1);

    INORDER(t.HEAD);
    cout << '\n';

    t.SHOW_ME_THE_TREE();
}