#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int v) : left{0}, right{0}, data{v}{}
};

void Inorder(Node* root) {
    cout << "InOrder Iterative: " << endl;
    if(root) {
        stack<Node*> stk;
        //initial step
        Node* ptr = root;

        while( ptr != 0 || !stk.empty()) {
           if(ptr != 0) {
                stk.push(ptr);
                ptr=ptr->left;
           } else {
               ptr = stk.top();
               stk.pop();
               cout << ptr->data << " ";
               ptr = ptr->right;
           }
        }
    }

}

Node* Insert(Node* root, int data) {
    if(root == 0) {
        root = new Node(data);
        return root;
    }

    if(root->left == 0 && root->right == 0) {
        if(root->data > data) {
            root->left = new Node(data);
        } else if(root->data < data) {
            root->right = new Node(data);
        }
    }

    if(root->data > data) {
        root->left = Insert(root->left, data);
    } else if(root->data < data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

int main() {
    vector<int> vect{2, 6, 12, 9, 4, 17, 22};
    Node* root = 0;
    root = Insert(root, 1);

    for(int v: vect) {
        Insert(root, v);
    }

    Inorder(root);
    return 0;

}