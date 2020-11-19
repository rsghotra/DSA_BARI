#ifndef STACK_H
#define STACK_H
#include "Queue.h"


class Stack {
    private:
    public:
        Node* top;
        Stack();
        ~Stack();
        void push(Node*);
        Node* pop();
        Node* peek();
        bool isEmpty();
        bool isFull();
};  

#endif