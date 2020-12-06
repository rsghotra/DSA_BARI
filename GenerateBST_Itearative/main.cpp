#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int v) : left{0}, right{0}, data{v}{}
};

void Inorder(Node* root) {
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

Node* GenerateBST(vector<int> preorder) {
    //setup
    stack<Node*> stk;
    //initial step
    int i = 0;
    Node* root = new Node(preorder[i]);
    stk.push(root);
    Node* ptr = root;
    Node* temp = 0;
    i++;
    while(i < preorder.size()) {
        if(ptr->data > preorder[i]) {
            temp = new Node(preorder.at(i));
            ptr->left = temp;
            stk.push(ptr);
            //key piece
            ptr = temp;
            i++;
        } else if((preorder[i] > ptr->data)&&(stk.empty() || preorder[i] < stk.top()->data)) {
            temp = new Node(preorder.at(i));
            //now I need to find out if this is actually its proper place
            //it should be greater than ptr but less than top of stack
                ptr->right = temp;
                ptr = temp;
                i++;
        }
        else {
            ptr = stk.top();
            stk.pop();
        }
    }
    return root;
}

int main () {
    vector<int> preorder{30,20,10,15,25,40,50,45};

    Node* root = GenerateBST(preorder);
    Inorder(root);
    cout << endl;
}

