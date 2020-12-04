#include<iostream>
#include<queue>
#include<stack>
#include<array>
#include<vector>
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
        int  SearchInorder(const vector<int>& inorder, int start, int end, int val);
        Node* GenerateBT(const vector<int>& inorder, const vector<int>& preorder, int inorderStart, int inorderEnd);
        int Height(Node*) const;
        int Sum(const Node* root) const;
        int CountNodes(const Node* root) const;
        int CountDegree0Nodes(const Node* root) const;
        int CountDegree1Nodes(const Node* root) const;
        int CountDegree2Nodes(const Node* root) const;
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
    long int addr;
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

int BinaryTree::SearchInorder(const vector<int>& inorder, int start, int end, int val) {
    int index;
    for(int i{start}; i < end; ++i) {
        if(inorder[i] == val) {
            index = i;
            break;
        }
    }
    return index;
}

Node* BinaryTree::GenerateBT(const vector<int>& inorder, const vector<int>& preorder, int inOrderStart, int inOrderEnd) {
    static int preIndex = 0;

    //terminating condition
    if(inOrderStart > inOrderEnd) {
        return nullptr;
    }

    //Each element of preorder will be considered as root
    Node* root = new Node; 
    root->data = preorder[preIndex];
    preIndex++;

    //if dealing with leaf node
    if(inOrderStart == inOrderEnd) {
        root->left = 0;
        root->right = 0;
        return root;
    } 

    int splitIndex = SearchInorder(inorder, inOrderStart, inOrderEnd, root->data);
    root->left = GenerateBT(inorder, preorder, inOrderStart, splitIndex-1);
    root->right = GenerateBT(inorder, preorder, splitIndex+1, inOrderEnd);
    return root;
}


int BinaryTree::Height(Node* root) const {
    //base conditions
    if(root == 0) return 0;
    if(root->left == 0 && root->right == 0) return 0;

    //most of the trees algos are implemented in postorder form
    int leftSubTreeHeight = Height(root->left);
    int rightSubTreeHeight = Height(root->right);

    if(leftSubTreeHeight > rightSubTreeHeight) {
        return leftSubTreeHeight + 1; 
    } else {
        return rightSubTreeHeight + 1;
    }
}

int BinaryTree::CountDegree0Nodes(const Node* root) const {
    if(root == 0) {
        return 0;
    }
    int leftSideCount = CountDegree0Nodes(root->left);
    int rightSideCount = CountDegree0Nodes(root->right);

    if(root->left == 0 && root->right == 0) {
        return leftSideCount + rightSideCount + 1;
    } else {
        return leftSideCount + rightSideCount;
    }
}

int BinaryTree::CountDegree2Nodes(const Node* root) const {
    if(root == 0) {
        return 0;
    }
    int leftSideCount = CountDegree2Nodes(root->left);
    int rightSideCount = CountDegree2Nodes(root->right);

    //leaf node detected
    if(root->left != 0 && root->right != 0) {
        return leftSideCount + rightSideCount + 1;
    } else {
        return leftSideCount + rightSideCount;
    }
}

int BinaryTree::CountDegree1Nodes(const Node* root) const {
    if(root == 0) {
        return 0;
    }

    int leftSideCount = CountDegree1Nodes(root->left);
    int rightSideCount = CountDegree1Nodes(root->right);

    if(root->left != 0 ^ root->right != 0) {
        return leftSideCount + rightSideCount + 1;
    } else {
        return leftSideCount + rightSideCount;
    }
}

int BinaryTree::CountNodes(const Node* root) const {
    if(root == 0) {
        return 0;
    }
    int leftNodes = CountNodes(root->left);
    int rightNodes = CountNodes(root->right);

    return leftNodes + rightNodes + 1;
}

int BinaryTree::Sum(const Node* root) const {
    if(root == 0) {
        return 0;
    }

    int leftNodeSum = Sum(root->left);
    int rightNodeSum = Sum(root->right);

    return leftNodeSum + rightNodeSum + root->data;
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

    vector<int> inorder{7,6,9,3,4,5,8,2,1};
    vector<int> preorder{4,7,9,6,3,2,5,8,1};
    bt.root = bt.GenerateBT(inorder, preorder, 0, inorder.size() - 1);

    cout << "\n\n>==>Generated Tree Traversal: " << endl;
    cout << "\n\n>==PreOrder Iterative: " << endl;
    bt.PreOrder_i();

    cout << ">==InOrder Iterative: " << endl;
    bt.InOrder_i();

    cout << ">==Postorder Iterative: " << endl;
    bt.PostOrder_i();

    cout << "\n\n>==>Simple Tree Functions: " << endl;

    cout << "Height of Tree: " << bt.Height(bt.root) << endl;
    cout << "Sum of Tree: " << bt.Sum(bt.root) << endl;
    cout << "Number Nodes of Tree: " << bt.CountNodes(bt.root) << endl;
    cout << "Degree 0 Nodes: " << bt.CountDegree0Nodes(bt.root) << endl;
    cout << "Degree 1 Nodes: " << bt.CountDegree1Nodes(bt.root) << endl;
    cout << "Degree 2 Nodes: " << bt.CountDegree2Nodes(bt.root) << endl;
    return 0;
}