#include<iostream>
using namespace std;

/*
    AVL - Fully Balanced BST
*/
class Node {
    Node* left;
    int data;
    Node* right;
    int height;
};

class AVL {
    public:
        Node* root;
        AVL() {
            this->root = NULL;
        }
        //HELPER METHODS FOR INSERTING A NODE IN AVL TREE
        int NodeHeight(Node*);
        int BalanceFactor(Node*);
        Node* LLRotation(Node*);
        Node* RRRotation(Node*);
        Node* LRRotation(Node*);
        Node* RLRotation(Node*);

        //Insert - Recursive
        Node* rInsert(Node*, int);

        //Traversal - Recursive
        void InOrder(Node* p);
        void InOrder() {InOrder(root);}

        //Aux
        Node* getRoot() {return root;}
};

int main() {

}