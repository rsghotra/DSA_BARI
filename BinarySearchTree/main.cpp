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
};


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
    int pre[8] = {30,20,10,15,25,40,50,45};
    BST* bst = new BST();
    bst->GenerateBSTUsingPreOrder(pre, 8);
    bst->InOrder(bst->root);
    return 0;
}