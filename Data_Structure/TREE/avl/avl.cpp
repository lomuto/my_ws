#include <bits/stdc++.h>

using namespace std;

/*************************************************/
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node();
    Node(int v);
};

Node::Node()
    : Node(-1) {}

Node::Node(int v)
    : data(v), left(nullptr), right(nullptr), height(-1) {}

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

int main() {
}