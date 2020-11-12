#include<iostream>
using namespace std;

// AS we representing stack as a linked list
/*
 - we will always insert or delete node from head
*/

struct Node {
    int data;
    Node* next;
};

Node* stk1;
Node* stk2;

bool isEmpty(Node* top) {
    if(!top) return true;
    else return false;
}

bool isFull(Node* top) {
    //since it is a LL so  unlimited capacity unless Heap is full
    Node * t = new Node;
    if(!t) return true;
    return false;
}

//no need to 
Node* push(Node* top, int x) {
    Node* t = new Node;
    t->data = x;
    t->next = top;
    top = t;
    return top;
}

Node* pop(Node* top) {
    if(!top) {
        cout << "Stack Underflow, can't pop." << endl;
        return nullptr;
    }
    Node* p = top;
    top = top->next;
    p = 0;
    return top;
}

void display(Node* top) {
    Node* p = top;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int peek(Node* top, int pos) {
    Node* p = top;
    for(int i=0;p!=NULL && i<pos-1;i++) {
        p = p->next;
    }
    if(!p) {
        cout << "Invalid index supplied. Can's peek" << endl;
        return -1;
    } else {
        return p->data;
    }
}

int stackTop(Node* top) {
    if(top) return top->data;
}

void enqueue(int x) {
    //always push in Stack1.
    stk1 = push(stk1, x);
}

void dequeue() {
    //main thing will happen here
    int ele;
    if(!isEmpty(stk2)) {
        cout << "Dequeued: " << stackTop(stk2) << endl;
        stk2=pop(stk2);
    } else {
        //stack2 is empty
        //check if stack1 is empty of not
        if(isEmpty(stk1)) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
        } else {
            //pop all element of stack1 and push on to stack1
            while(!isEmpty(stk1)) {
                stk2=push(stk2, stackTop(stk1));
                stk1=pop(stk1);
            }
            //once all elements of stk1 are in stk2 - we are ready to roll!
            cout <<"Dequeued: " << stackTop(stk2) << endl;
            stk2=pop(stk2);
        }
    }
}

void printQueue() {
    //first empty stk2
    if(!isEmpty(stk2)) {
        while(!isEmpty(stk2)) {
            cout << stackTop(stk2) << " ";
            stk2 = pop(stk2);
        }
    }
    if(!isEmpty(stk1)) {
        while(!isEmpty(stk1)) {
            stk2 = push(stk2, stackTop(stk1));
            stk1 = pop(stk1);
        }
    }
    if(!isEmpty(stk2)) {
        while(!isEmpty(stk2)) {
            cout << stackTop(stk2) << " ";
            stk2 = pop(stk2);
        }
    }
}

int main() {
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue();
    dequeue();
    printQueue();
}