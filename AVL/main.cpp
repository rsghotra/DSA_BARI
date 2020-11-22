#include<iostream>
using namespace std;

/*
    AVL - Fully Balanced BST
*/
class Node {
    public:
        Node* left;
        int data;
        Node* right;
        int height;
};

class AVL {
    public:
        Node* root=0;
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

        //Aux
        Node* getRoot() {return root;}
};

void AVL::InOrder(Node* ptr) {
    if(ptr) {
        InOrder(ptr->left);
        cout << ptr->data << " ";
        InOrder(ptr->right);
    }
}


int AVL::BalanceFactor(Node* ptr) {
    int hl = 0, hr = 0;
    if(ptr == 0 && ptr->left) {
        hl = ptr->left->height;
    }
    if(ptr == 0 && ptr->right) {
        hr = ptr->right->height;
    }
    return hl - hr;
}

//no need of doing recursion as we have already stored the height information
int AVL::NodeHeight(Node* ptr) {
    int hl = 0, hr = 0;
    if(ptr == 0 && ptr->left) {
        hl = ptr->left->height;
    }
    if(ptr == 0 && ptr->right) {
        hr = ptr->right->height;
    }
    if(hl > hr) {
        return hl + 1;
    } else {
        return hr + 1;
    }
}

Node* AVL::LLRotation(Node* p) {
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if(root = p) {
        root = pl;
    }
}

Node* AVL::RRRotation(Node* p) {
    return nullptr;
}

Node* AVL::LRRotation(Node* p) {
    Node* pl = p->left;
    Node* plr = pl->right;

    //bachey sambhal liye
    pl->right = plr->left;
    p->left = plr->right;
    
    plr->left = pl;
    plr->right=p;

    //perform height update
    pl->height = NodeHeight(pl);
    p->height  = NodeHeight(p);
    plr->height = NodeHeight(plr);
    if(this->root == p) {
        this->root = plr;
    }
    return plr;
}

Node* AVL::RLRotation(Node* p) {
    return nullptr;
}

//taking height as 1
Node* AVL::rInsert(Node* ptr, int key) {
    Node* temp = 0;
    if(ptr == 0) {
        temp = new Node;
        temp->data = key;
        temp->left = temp->right = 0;
        temp->height = 1;
        return temp;
    } else {
        if(ptr->data > key) {
            ptr->left = rInsert(ptr->left, key);
        } else if(ptr->data < key) {
            ptr->right = rInsert(ptr->right, key);
        }
        //now need to change height of every node in the subtree
        ptr->height = NodeHeight(ptr);
        //Left Side heavy +2, +1; LL Rotation
        if(BalanceFactor(ptr) == 2 && BalanceFactor(ptr->left) == 1) {
            return LLRotation(ptr);
        } else if(BalanceFactor(ptr) == 2 && BalanceFactor(ptr->left) == -1) {
            return LRRotation(ptr);
        } else if(BalanceFactor(ptr) == -2 && BalanceFactor(ptr->right) == -1) {
            return RRRotation(ptr);
        } else if(BalanceFactor(ptr) == -2 && BalanceFactor(ptr->right) == 1) {
            return RLRotation(ptr);
        }
        return ptr;
    }
}

int main() {
    AVL avl;
    avl.root = avl.rInsert(avl.root,10);
    avl.rInsert(avl.root,5);
    avl.rInsert(avl.root,2);

    avl.InOrder(avl.root);
    return 0;
}