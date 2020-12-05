#include<iostream>
#include<queue>
#include<stack>
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
    cout << "Enter root node of your Binary Tree: ";
    cin >> root->data;
    cout << endl;
    Q.push(root);

    //iterative step
    while(!Q.empty()) {
        ptr = Q.front();
        Q.pop();

        cout << "Enter left child of " << ptr->data << ": ";
        cin >> x;
        cout << endl;
        if(x != -1) {
            temp = new Node();
            temp->data = x;
            ptr->left = temp;
            Q.push(temp);
        }
        cout << "Enter right child of " << ptr->data << ": ";
        cin >> x;
        cout << endl;
        if(x != -1) {
            temp = new Node();
            temp->data = x;
            ptr->right = temp;
            Q.push(temp);
        }
    }
    return root;
}

void InOrder(Node* root) {
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

void PreOrder(Node* root) {
    cout << "\nPreOrder Iterative: " << endl;
    if(root) {
        stack<Node*> stk;
        //initial step
        Node* ptr = root;
        //stack will begin from empty statte
        while( ptr != 0 || !stk.empty()) {
           if(ptr != 0) {
                cout << ptr->data << " ";
                stk.push(ptr);
                ptr = ptr->left;
           } else {
               ptr = stk.top();
               stk.pop();
               ptr = ptr->right;
           }
        }
    }

}

void PostOrder(Node* root) {
    cout << "\nPostOrder Iterative: " << endl;
    if(root) {
        stack<long int> stk;
        long int temp;
        Node* ptr = root;

        while(ptr != 0 || !stk.empty()) {
            if(ptr != 0) {
                temp = reinterpret_cast<uintptr_t>(ptr);
                stk.push(temp);
                ptr = ptr->left;
            } else {
                temp = stk.top();
                stk.pop();
                if(temp > 0) {
                    ptr = reinterpret_cast<Node*>(temp);
                    ptr = ptr->right;
                    stk.push(-temp);
                } else {
                    ptr = reinterpret_cast<Node*>((-1)* temp);
                    cout << ptr->data << " ";
                    ptr = 0;
                }
            }
        }
    }
}


int main() {
    Node* root = Create();

    InOrder(root);

    PreOrder(root);

    PostOrder(root);

}