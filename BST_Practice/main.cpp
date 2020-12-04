#include<iostream>
#include<array>
#include<queue>
#include<stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node() : val{0}, left{0}, right{0}{}
    Node(int v) : val{v}, left{0}, right{0}{}
};

class BST {
    public:
        Node* root;
        BST() {this->root = 0;}
        void InOrder(Node*) const;
        Node* Search(Node*, int) const;
        Node* Search_i(Node*, int) const;
        Node* Insert(Node*, int);
        Node* Insert_i(Node*, int);
};

Node* BST::Insert(Node* root, int data) {
    //in trees recursion termination and insertion happen at leaf node
    if(root == 0) {
        Node* temp = new Node(data);
        return temp;
    }
    if(root->val > data) {
        root->left = Insert(root->left, data);
    } else if(root->val < data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

Node* BST::Insert_i(Node* root, int data) {
    //inorder to insert in tree - two pointers are user - head pointer and tail pointers
    Node* temp = new Node(data);

    if(root == 0) return temp;

    Node* ptr = root;
    Node* qtr = 0;

    while(ptr) {
        qtr = ptr;
        if(ptr->val > temp->val) {
            ptr = ptr->left;
        } else if(ptr->val < temp->val) {
            ptr = ptr->right;
        } else {
            return nullptr;
        }
    }

    if(qtr && qtr->val > temp->val) {
        qtr->left = temp;
    } else if(qtr && qtr->val < temp->val) {
        qtr->right = temp;
    }
    return root;
}

void BST::InOrder(Node* root) const{
    if(root) {
        InOrder(root->left);
        cout << root->val << " ";
        InOrder(root->right);
    }
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

int main() {
    BST* bst = new BST();

    cout << "\n>==>Creating BST using INSERT." << endl;
    bst->root = bst->Insert(bst->root, 10);
    bst->Insert(bst->root, 5);
    bst->Insert(bst->root, 20);
    bst->Insert(bst->root, 8);
    bst->Insert(bst->root, 30);
    cout << "\n>==>Displaying Created BST - InOrder" << endl;
    bst->InOrder(bst->root);

    cout << "\n>==>Searching for 5 in BST." << endl;
    if(bst->Search(bst->root, 5)) 
        cout << "Element found." << endl;
    else 
        cout << "Element not found.\n";

    cout << "\n>==>Searching for 11 in BST." << endl;
    if(bst->Search(bst->root, 11)) 
        cout << "Element found." << endl;
    else 
        cout << "Element not found.\n";
    
    bst->Search_i(bst->root, 10) ? "Element found." : "Element not found.\n";


    cout << "INSERT IN A TREE - ITERATIVE\n";
    bst->root = 0;
    bst->root = bst->Insert_i(bst->root, 11);
    bst->Insert_i(bst->root, 13);
    bst->Insert_i(bst->root, 5);
    bst->Insert_i(bst->root, 23);
    bst->Insert_i(bst->root, 29);
    cout << "\n>==>Displaying Created BST - InOrder" << endl;
    bst->InOrder(bst->root);

    cout << "\n>==>Searching for 5 in BST." << endl;
    if(bst->Search(bst->root, 5)) 
        cout << "Element found." << endl;
    else 
        cout << "Element not found.\n";

    cout << "\n>==>Searching for 11 in BST." << endl;
    if(bst->Search(bst->root, 11)) 
        cout << "Element found." << endl;
    else 
        cout << "Element not found.\n";
    
    bst->Search_i(bst->root, 10) ? "Element found." : "Element not found.\n";
}