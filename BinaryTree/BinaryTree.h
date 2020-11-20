#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Queue.h"

class BinaryTree {
    private:
        void PreOrder(Node*);
        void InOrder(Node*);
        void PostOrder(Node*);
        int  Count(Node*);
        int  Sum(Node*);
        int  CountLeafNodes(Node*);
        int  CountNonLeafNodes(Node*);
    public:
        Node* root;
        BinaryTree();
        ~BinaryTree();
        void CreateTree();
        void PreOrder_R();
        void InOrder_R();
        void PostOrder_R();
        void LevelOrder();
        void PreOrder_I();
        void InOrder_I();
        void PostOrder_I();
        int  Count();
        int  Sum();
        int  CountLeafNodes();
        int  CountNonLeafNodes();
        // int Height();
        
        // int  CountDeg2Nodes();
        // int  CountDeg1Nodes();
        //Node* GenerateBTFromTraversal(int*, int*, int, int);
};

#endif