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
    //Initialize Queue
    BinaryTree* bt = new BinaryTree();
    bt->CreateTree();
    bt->InOrder_R();
    return 0;
}