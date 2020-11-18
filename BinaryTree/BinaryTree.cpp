#include<iostream>
using namespace std;
#include "BinaryTree.h"
#include "Queue.h"

BinaryTree::BinaryTree() {
    this->root = NULL;
}

BinaryTree::~BinaryTree() {
    this->root = 0;
}

void BinaryTree::CreateTree() {
    Node*t, *p;
    int x;
    cout << "Enter root value of BT: " << endl;
    cin >> x;

    /*
        initial step to create a Queue and create root node;
    */
   Queue q(100);
   t = new Node;
   t->left = t->right = 0;
   t->val = x;
   q.enqueue(t);

   while(!q.isEmpty()) {
       /*
            - First Left Child
            - Then, Right Child
       */
      p = q.dequeue();

      cout << "Enter left child of " << p->val << " " << endl;
      cin >> x;
      if(x != -1) {
          t = new Node;
          t->val = x;
          t->left = t->right = 0;
          p->left = t;
          q.enqueue(t);
      }
      cout << "Enter right child of " << p->val << " " << endl;
      cin >> x;
      if(x!=-1) {
          t = new Node;
          t->val = x;
          t->left = t->right = 0;
          p->right = t;
          q.enqueue(t);
      }
   }
}

void BinaryTree::InOrder(Node* p) {
    if(p) {
        InOrder(p->left);
        cout <<  p->val << " ";
        InOrder(p->right);
    }
} 

void BinaryTree::InOrder_R() {
    InOrder(this->root);
}
