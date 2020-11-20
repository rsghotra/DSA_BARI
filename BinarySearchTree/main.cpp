#include<iostream>
#include<stack>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
};

class BST {
    public:
        Node* root;
        BST() {
            this->root = 0;
        }
        void GenerateBSTUsingPreOrder(int[], int);
        void InOrder(Node*);
        Node* Insert_I(Node*, int);
        Node* Insert_R(Node*, int);
        //Node* Search_I(Node*, int);
        //Node* Search_R(Node*, int);
};


Node* BST::Insert_I(Node* ptr, int key) {
    /*
        - Because it is a case of Tail Recursion - we will not need any stack
    */
    //setup
    Node* tail = 0; //follower
    Node* temp = 0; //creator

    //initialization of actors
    temp = new Node;
    temp->val = key;
    temp->left = temp->right = 0;

    //repetitive step
    //special case - when root node is null - means it will be the first node
    if(ptr == 0) {
        ptr = temp;
        return ptr;
    }
    //As incoming will not be root node, now it is time to find the righteous placei in BST.
    while(ptr!=0) {
        tail = ptr;
        if(ptr->val > key) {
            ptr = ptr->left;
        } else if(ptr->val < key) {
            ptr = ptr->right;
        } else {
            cout << "Duplicate value find. Can't insert as it is a BST" << endl;
            return ptr;
        }
    }
    if(tail->val > temp->val) {
        //means the child must be its left child
        tail->left = temp;
    } else {
        tail->right = temp;
    }
    //though this is redundant
    return tail;
}

Node* BST::Insert_R(Node* ptr, int key) {
    /*
        Tail Recursion
    */
    Node* temp = 0;
    if(ptr == 0) {
        //insertion will happen here
        temp = new Node;
        temp->val = key;
        temp->left = temp->right = 0;
        return temp;
    } else {
        if(ptr->val > key) {
            ptr->left = Insert_R(ptr->left, key);
        } else if(ptr->val < key) {
            ptr->right = Insert_R(ptr->right, key);
        }
        return ptr;
    }
}

void BST::GenerateBSTUsingPreOrder(int preOrder[], int n) {
    stack<Node*> stk;
    Node* ptr; //the traveller
    Node* temp;//the creator
    int i = 0; //the guide
    /*
        Initial step
    */
    this->root = new Node;
    root->left = root->right = 0;
    root->val = preOrder[i];

    //Ready for the journey
    i = 1;
    ptr = root;
   /*
        Repeating step
   */
    while(i<n) {
        if(preOrder[i] < ptr->val) {
            temp = new Node;
            temp->val = preOrder[i];
            temp->left = temp->right = 0;
            ptr->left = temp;
            stk.push(ptr);
            ptr = temp;
            i++;
        } else {
            /*
                Two conditions: we must ensure if the incoming is ACTUALLY a RIGHT CHILD OF CURRENT NODE. IF NOT THEN LOOK FOR ITS RIGHTEOUS PLACE 
            */
           if((preOrder[i] > ptr->val)&&(stk.empty() || preOrder[i] < stk.top()->val)) {
               temp = new Node;
                temp->val = preOrder[i];
                temp->left = temp->right = 0;
                ptr->right = temp;
                i++;
                ptr = temp;
           }
           else  {
               ptr = stk.top();
               stk.pop();
           }
        }
    }
}

void BST::InOrder(Node* p) {
    if(p) {
        InOrder(p->left);
        cout <<  p->val << " ";
        InOrder(p->right);
    }
} 

int main() {
    // int pre[8] = {30,20,10,15,25,40,50,45};
    // BST* bst1 = new BST();
    // bst1->GenerateBSTUsingPreOrder(pre, 8);
    // bst1->InOrder(bst1->root);
    // cout << endl;
    BST* bst2 = new BST();
    bst2->root = bst2->Insert_R(bst2->root, 20);
    bst2->Insert_R(bst2->root, 30);
    bst2->Insert_R(bst2->root, 40);
    bst2->Insert_I(bst2->root, 10);
    bst2->Insert_I(bst2->root, 50);
    bst2->InOrder(bst2->root);
    return 0;
}