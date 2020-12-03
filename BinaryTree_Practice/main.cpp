#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;
//linked representation


struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    private:
    public:
        Node* root;
        BinaryTree();
        ~BinaryTree();
        void Create();
        void LevelOrder() const;
        void PreOrder(Node*) const;
        void InOrder(Node*) const;
        void PostOrder(Node*) const;
        void PreOrder() const{cout <<"\nPreOrder: ";PreOrder(this->root);cout <<"\n"<< endl;};
        void InOrder() const{cout <<"\nInOrder: ";InOrder(this->root);cout <<"\n"<< endl;};
        void PostOrder() const{cout <<"\nInOrder: ";PostOrder(this->root);cout<<"\n"<<endl;};
};

BinaryTree::BinaryTree() {
    this->root = 0;
}

BinaryTree::~BinaryTree() {
    delete root;
    this->root = 0;
}

void BinaryTree::Create() {
    queue<Node*> Q;
    Node* temp = new Node;
    temp->left = 0;
    temp->right = 0;
    cout << "\nEnter root node value: ";
    cin >> setw(2) >> temp->data;

    this->root = temp;
    Q.push(temp);
    int x;
    Node* ptr=0;
    while(!Q.empty()) {
        ptr = Q.front();
        Q.pop();
        cout << "Enter left child of" << setw(2) << ptr->data << ": ";
        cin >> x;
        if(x != -1) {
            temp = new Node();
            temp->left = temp->right = 0;
            temp->data = x;
            Q.push(temp);

            //setup left child
            ptr->left = temp;
        } 
        cout << "Enter right child of" << setw(2) << ptr->data << ": ";
        cin >> x;
        if(x != -1) {
            temp = new Node();
            temp->left = temp->right = 0;
            temp->data = x;
            Q.push(temp);

            //setup right child
            ptr->right = temp;
        }
    }
}

void BinaryTree::PreOrder(Node* ptr) const  {
    if(ptr) {
        cout << ptr->data << " ";
        PreOrder(ptr->left);
        PreOrder(ptr->right);
    }
}

void BinaryTree::InOrder(Node* ptr)  const {
    if(ptr) {
        InOrder(ptr->left);
        cout << ptr->data << " ";
        InOrder(ptr->right);
    }
}

void BinaryTree::PostOrder(Node* ptr) const {
    if(ptr) {
        PostOrder(ptr->left);
        PostOrder(ptr->right);
        cout << ptr->data << " ";
    }
}

int main() {
    BinaryTree bt;
    bt.Create();
    cout << endl;
    bt.InOrder();
    bt.PreOrder();
    bt.PostOrder();
    return 0;
}