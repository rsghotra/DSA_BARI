#include<iostream>
using namespace std;

//BST implementation

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int data;
    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): data(x), left(left), right(right) {}
};

//BST - Search Operation
/*
  1. Start search from the root node
*/

void insert(TreeNode* root, int data) {

}

TreeNode* search(TreeNode* root, int data) {
    TreeNode* current= root;
    cout<<"Visiting Elements: ";

    while(current->data != data) {
        if(current == NULL) return nullptr;
        cout << current->data << " ";
        if(data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}



int main() {
    TreeNode* root = new TreeNode(13);
    cout << root->data << endl;
    cout << root->left << endl;
    cout << root->right << endl;
    return 0;
}
