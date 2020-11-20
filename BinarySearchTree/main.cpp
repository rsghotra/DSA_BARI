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
        Node* Search_I(Node*, int);
        Node* Search_R(Node*, int);
        Node* Delete(Node*, int);
        int   Height(Node*);
        Node* InOrderPred(Node*);
        Node* InOrderSucc(Node*);
};

Node* BST::Search_I(Node* ptr, int key) {
    if(ptr == 0) return nullptr;
    while(ptr!= 0) {
        if(ptr->val == key) {
            return ptr;
        }
        if(ptr->val > key) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    return nullptr;
}

Node* BST::Search_R(Node* ptr, int key) {
    if(ptr == 0) {
        return nullptr;
    }
    if(ptr->val == key) {
        return ptr;
    }
    if(ptr->val > key) {
        return Search_R(ptr->left, key);
    } else {
        return Search_R(ptr->right, key);
    }
}

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
                Two conditions: we must ensure if the incoming is ACTUALLY a RIGHT CHILD OF CURRENT NODE. 
                IF NOT THEN LOOK FOR ITS RIGHTEOUS PLACE 
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

int BST::Height(Node* ptr) {
    int x, y;
    if(ptr == 0) {
        return 0;
    }
    if(ptr->left == 0 && ptr->right == 0) {
        return 0;
    }
    x = Height(ptr->left);
    y = Height(ptr->right);
    if(x>y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

Node* BST::InOrderPred(Node* ptr) {
    while(ptr && ptr->right) {
        ptr = ptr->right;
    }
    return ptr;
}

Node* BST::InOrderSucc(Node* ptr) {
    while(ptr && ptr->left) {
        ptr = ptr->left;
    }
    return ptr;
}

Node* BST::Delete(Node* ptr, int key) {
    Node* temp = 0;
    if(ptr == 0) {
        return nullptr;
    }
    //delation happen here
    if(ptr->val == key && ptr->left == 0 && ptr->right == 0) {
        //edge case if it is the last node of the tree
        if(ptr == this->root) {
            this->root = 0;
        }
        delete ptr;
        ptr = 0;
        return nullptr;
    }
    if(ptr->val > key) {
        ptr->left = Delete(ptr->left, key);
    } else if(ptr->val < key) {
        ptr->right = Delete(ptr->right, key);
    } else {
        //when the elemenet is found
        if(Height(ptr->left) > Height(ptr->right)) {
            // means need to find InOrder Predecessor
            temp = InOrderPred(ptr->left);
            //deletion by copying
            ptr->val = temp->val;
            //assigned to ptr->left for keeping pattern in the code - though not required
            ptr->left = Delete(ptr->left, temp->val);
        } else {
            //means need to find InOrder Successor
            temp = InOrderSucc(ptr->right);
            ptr->val = temp->val;
            //assigned to ptr->right for keeping pattern in the code - though not required
            ptr->right = Delete(ptr->right, temp->val);
        }
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
    if(bst2->Search_I(bst2->root, 40)) {
        cout << "\nElement 40 found." << endl;
    } else {
        cout << "Element not found." << endl;
    }

    if(bst2->Search_R(bst2->root, 60)) {
        cout << "Element 40 found." << endl;
    } else {
        cout << "Element not found." << endl;
    }

    bst2->Delete(bst2->root, 10);
    bst2->InOrder(bst2->root);
    return 0;
}