#include<iostream>
#include<queue>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node() : left{0}, right{0}{}
};

Node* Create() {
    //setup
    queue<Node*> Q;
    Node* temp = 0;
    Node* ptr;
    int x;
    //initial step
    Node* root = new Node();
    cout << "\nEnter root node of your Binary Tree: ";
    cin >> root->data;
    Q.push(root);

    //iterative step
    while(!Q.empty()) {
        ptr = Q.front();
        Q.pop();

        cout << "\nEnter left child of " << ptr->data << endl;
        cin >> x;
        if(x != -1) {
            temp = new Node();
            temp->data = x;
            ptr->left = temp;
            Q.push(temp);
        }
        cout << "\nEnter right child of " << ptr->data << endl;
        cin >> x;
        if(x != -1) {
            temp = new Node();
            temp->data = x;
            ptr->right = temp;
            Q.push(temp);
        }
    }
    return root;
}

void LevelOrder(Node* root) {
    queue<Node*> Q;
    Node* temp = 0;
    if(root) {
        Q.push(root);

        while(!Q.empty()) {
            //print; explore and enqueue children
            temp = Q.front();
            Q.pop();
            cout << temp->data << " ";
            if(temp->left) Q.push(temp->left);
            if(temp->right) Q.push(temp->right);
        }
    }
    cout << endl;
}

int main() {
    Node* root = Create();

    LevelOrder(root);

}