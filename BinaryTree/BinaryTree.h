#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Queue.h"

class BinaryTree {
    private:
        void InOrder(Node*);
        void PostOrder(Node*);
        int  Count(Node*);
        int  Sum(Node*);
        int  CountLeafNodes(Node*);
        int  CountDegOneNodes(Node*);
        int  Height(Node*);
        int  SearchInorder(int*, int, int, int);
    public:
        Node* root;
        BinaryTree();
        ~BinaryTree();
        void CreateTree();
        void PreOrder_R();
        void InOrder_R();
        void PostOrder_R();
        void LevelOrder();
        void PreOrder(Node*);
        void PreOrder_I();
        void InOrder_I();
        void PostOrder_I();
        int  Count();
        int  Sum();
        int  CountLeafNodes();
        int  CountDegOneNodes();
        int Height();
        // Reference: https://algorithms.tutorialhorizon.com/make-a-binary-tree-from-given-inorder-and-preorder-traveral/
        Node* GenerateBTFromTraversal(int*, int*, int, int);
};

#endif