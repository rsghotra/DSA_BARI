#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Queue.h"

class BinaryTree {
    private:
        Node* root;
    public:
        BinaryTree();
        ~BinaryTree();
        void CreateTree();
        //void PreOrder_R();
        void InOrder(Node*);
        void InOrder_R();
        // void PostOrder_R();
        // void LevelOrder_R();
        // void PreOrder_I();
        // void InOrder_I();
        // void PostOrder_I();
        // void LevelOrder_I();
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