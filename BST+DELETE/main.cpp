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

Node* Insert(Node* root, int data) {
    if(root == 0) {
        root = new Node(data);
        return root;
    }

    if(root->left == 0 && root->right == 0) {
        if(root->data > data) {
            root->left = new Node(data);
        } else if(root->data < data) {
            root->right = new Node(data);
        }
    }

    if(root->data > data) {
        root->left = Insert(root->left, data);
    } else if(root->data < data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

int Height(Node* ptr) {
    if(ptr == 0) return 0;
    if(ptr->left == 0 && ptr->right == 0) return 0;
    int leftTree = Height(ptr->left);
    int rightTree = Height(ptr->right);

    if(leftTree > rightTree) {
        return leftTree + 1;
    } else {
        return rightTree + 1;
    }
}

Node* inOrderSuc(Node* ptr) {
    Node* temp = 0;
     if(ptr) {
        temp = ptr->right;
        while(temp && temp->left) {
            temp = temp->left;
        }
    }
    return temp;
}

Node* inOrderPred(Node* ptr) {
    Node* temp = 0;
    if(ptr) {
        temp = ptr->left;
        while(temp && temp->right) {
            temp = temp->right;
        }
    }
    return temp;
}

Node* Delete(Node* ptr, int data) {
    static Node* root = ptr;
    Node* temp = 0;
    if(ptr == 0) return nullptr;

    if(ptr->data == data && ptr->left == 0 && ptr->right == 0) {
        if(ptr == root) {
            root = 0;
        }
        delete ptr;
        ptr = 0;
        return nullptr;
    }

    if(ptr->data > data) {
        ptr->left = Delete(ptr->left, data);
    } else if(ptr->data < data) {
        ptr->right = Delete(ptr->right, data);
    } else {
        if(Height(ptr->left) > Height(ptr->right)) {
            temp = inOrderPred(ptr);
            ptr->data = temp->data;
            ptr->left = Delete(ptr->left, temp->data);
        } else {
            temp = inOrderSuc(ptr);
            ptr->data = temp->data;
            ptr->right =  Delete(ptr->right, temp->data);
        }
    }
}

int main() {
    vector<int> vect{2, 6, 12, 9, 4, 17, 22};
    Node* root = 0;
    root = Insert(root, 1);

    for(int v: vect) {
        Insert(root, v);
    }

    Inorder(root);
    Delete(root, 12);
    cout << endl;
    Inorder(root);
    return 0;

}