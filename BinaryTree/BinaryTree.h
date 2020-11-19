#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Queue.h"

class BinaryTree {
    private:
    public:
        Node* root;
        BinaryTree();
        ~BinaryTree();
        void CreateTree();
        void PreOrder(Node*);
        void PreOrder_R();
        void InOrder(Node*);
        void InOrder_R();
        void PostOrder(Node*);
        void PostOrder_R();
        void LevelOrder();
        void PreOrder_I();
        void InOrder_I();
        void PostOrder_I();
        // int  Height();
        // int  Count();
        // int  Sum();
        // int  CountLeafNodes();
        // int  CountNonLeafNodes();
        // int  CountDeg2Nodes();
        // int  CountDeg1Nodes();
        //Node* GenerateBTFromTraversal(int*, int*, int, int);
};

#endif