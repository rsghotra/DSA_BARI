#include<iostream>
#include<vector>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int val) : data{val}, left{0}, right{0} {}
};

void InOrder(Node* root) {
    if(root) {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}


int searchInorder(vector<int>& inorder, int data) {
    for(int i = 0; i < inorder.size(); i++) {
        if(inorder.at(i) == data) {
            return i;
        }
    }
    return -1;
}

Node* GenerateBT(vector<int>& preorder, vector<int>& inorder, int inOrderStart, int inOrderEnd) {
    static int preIndex = 0;

    if(inOrderStart > inOrderEnd) {
        return nullptr;
    }
    //every element of preorder will be considered root
    Node* root = new Node(preorder[preIndex]);
    preIndex++;

    if(inOrderStart == inOrderEnd) {
        //means leaf node;
        return root;
    }
    
    int splitIndex = searchInorder(inorder, root->data);
    root->left = GenerateBT(preorder, inorder, inOrderStart, splitIndex - 1);
    root->right = GenerateBT(preorder, inorder, splitIndex+1, inOrderEnd);
    
    return root;
}

int main () {
    vector<int> preorder{4,7,9,6,3,2,5,8,1};
    vector<int> inorder{7,6,9,3,4,5,8,2,1};

    Node* root = GenerateBT(preorder, inorder, 0, inorder.size() - 1);
    InOrder(root);
    cout << endl;
}

