#include<iostream>
#include<queue>
#include<stack>
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
        void PostOrder() const{cout <<"\nPostOrder: ";PostOrder(this->root);cout<<"\n"<<endl;};
        void PreOrder_i() const;
        void InOrder_i() const;
        void PostOrder_i() const;
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

void BinaryTree::LevelOrder() const {
    //non recursive; Queue will be used
    Node* ptr=0;
    if(!(this->root)) return;
    queue<Node*> Q;
    Q.push(this->root);
    cout << "Level Order: " << endl;
    while(!Q.empty()) {
        ptr = Q.front();
        Q.pop();

        cout << ptr->data << " ";
        if(ptr->left) {
            Q.push(ptr->left);
        }
        if(ptr->right) {
            Q.push(ptr->right);
        }
    }
    cout << endl;
}

void BinaryTree::InOrder_i() const {
    Node* ptr = this->root;
    stack<Node*> stk;

    while( ptr!= 0 || !stk.empty()) {
        if(ptr) {
            stk.push(ptr);
            ptr = ptr->left;
        } else { //ptr == 0; stack must be non-empty
            ptr = stk.top();
            stk.pop();
            cout << ptr->data << " ";
            ptr = ptr->right;
        }   
    }
    cout << endl;
}

void BinaryTree::PreOrder_i() const {
    Node* ptr = this->root;
    stack<Node*> stk;
    while(ptr != 0 || !stk.empty()) {
        if(ptr) {
            cout << ptr->data << " ";
            stk.push(ptr);
            ptr = ptr->left;
        } else {
            ptr = stk.top();
            stk.pop();
            ptr = ptr->right;
        }
    }
    cout << endl;
}

void BinaryTree::PostOrder_i() const {
    stack<long int> stk;
    Node* ptr = this->root;
    int addr;
    while(ptr != 0 || !stk.empty()) {
        if(ptr != 0) {
            addr = reinterpret_cast<uintptr_t>(ptr);
            stk.push(addr);
            ptr = ptr->left;
        }
        else {
            //ptr is null - reaching leaf node; Now key work
            addr = stk.top();
            stk.pop();
            if(addr < 0) {
                ptr = reinterpret_cast<Node*>((-1)* (addr));
                cout << ptr->data << " ";
                ptr=0;
            } else {
                ptr = reinterpret_cast<Node*>(addr);
                stk.push(-addr);
                ptr = ptr->right;
            }
        }
    }
}

int main() {
    BinaryTree bt;
    bt.Create();
    cout << endl;
    bt.InOrder();
    bt.PreOrder();
    bt.PostOrder();
    bt.LevelOrder();


    cout << "\n\n>==PreOrder Iterative: " << endl;
    bt.PreOrder_i();

    cout << ">==InOrder Iterative: " << endl;
    bt.InOrder_i();

    cout << ">==Postorder Iterative: " << endl;
    bt.PostOrder_i();
    return 0;
}