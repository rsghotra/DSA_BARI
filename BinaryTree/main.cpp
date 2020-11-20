#include<iostream>
#include "Queue.h"
#include "BinaryTree.h"
using namespace std;

/*
    Binary Tree Implementation and Algorithm
    1. Max Number of Nodes in tree of height h = 2^(h+1) -1
    2. Number of Binary Trees possible out of given 'n' nodes: T(n) = 2nCn/n+1

*/

int main() {
    BinaryTree* bt = new BinaryTree();
    //Tree creation using Level Order Traversal
    bt->CreateTree();
    cout << "Displaying InOrder Using Recursion: ";
    bt->InOrder_R();
    cout << "\nDisplaying PreOrder Using Recursion: ";
    bt->PreOrder_R();
    cout << "\nDisplaying PostOrder Using Recursion: ";
    bt->PostOrder_R();
    cout <<"\nDisplaying Level Order Traversal: ";
    bt->LevelOrder();
    // cout <<"\nDisplaying Pre-Order Iterative: ";
    // bt->PreOrder_I();
    // cout <<"\nDisplaying In-Order Iterative: ";
    // bt->InOrder_I();
    // cout <<"\nDisplaying PostOrder Iterative: ";
    // bt->PostOrder_I();
    cout << "\nDisplaying count of number of nodes: ";
    cout << bt->Count();
    cout << "\nDisplaying sum of data of all of the nodes: ";
    cout << bt->Sum();
    cout << "\nDisplaying Node with deg(0): Leaf Nodes: ";
    cout << bt->CountLeafNodes();
    cout << "\nDisplaying Node with deg(1): Non-Leaf Nodes: ";
    cout << bt->CountDegOneNodes();

    cout << "\nDisplaying Height of Binary Tree: ";
    cout << bt->Height();

    //cout << "\nGenerating Binary Tree using PreOrder and InOrder traversals: ";
    int preorder[] = {4,7,9,6,3,2,5,8,1};
    int inorder[] = {7,6,9,3,4,5,8,2,1};
    Node* T = bt->GenerateBTFromTraversal(preorder, inorder, 0, 8);
    //bt->root = T;
    //bt->PreOrder_R();
    return 0;
}