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
    return 0;
}