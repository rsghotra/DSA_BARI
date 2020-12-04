#include<iostream>
#include<array>
#include<queue>
#include<stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

class BST {
    public:
        Node* root;
        BST() {this->root = 0;}
        void LevelOrder(Node*) const;
        Node* Search(Node*, int) const;
        Node* Search_i(Node*, int) const;
};

void BST::LevelOrder(Node* root) const{
    Node* ptr=0;
    if(!(root)) return;
    queue<Node*> Q;
    Q.push(root);
    cout << "Level Order: " << endl;
    while(!Q.empty()) {
        ptr = Q.front();
        Q.pop();

        cout << ptr->val << " ";
        if(ptr->left) {
            Q.push(ptr->left);
        }
        if(ptr->right) {
            Q.push(ptr->right);
        }
    }
    cout << endl;
}

Node* BST::Search(Node* root, int data) const {
    if(root == 0) {
        return nullptr;
    }
    if(root->val == data) {
        return root;
    }
    if(root->val > data) return Search(root->left, data);
    else return Search(root->right, data);
}

Node* BST::Search_i(Node* root, int data) const {
    if(root == 0) return nullptr;

    while(!root) {
        if(root->val == data) return root;
        if(root->val > data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}