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

int main() {
    Node* st = 0;
    cout << ">==>Pushing elements into stack." << endl;
    cout << ">==>Is stack full." << endl;
    if(isEmpty(st)) {
        cout << "Stack is empty." << endl;
    }
    st=push(st, 10);
    st=push(st, 30);
    st=push(st, 40);
    st=push(st, 50);
    st=push(st, 60);
    st=push(st, 70);
    st=push(st, 80);
    st=push(st, 90);
    st=push(st, 100);
    cout << ">==>Displaying elements of stack." << endl;
    display(st);
    
    cout << ">==>Popping elements." << endl;
    st=pop(st);
    st=pop(st);
    st=pop(st) ;
    st=pop(st);
    st=pop(st);
    st=pop(st);
    st=pop(st);
    st=pop(st);
    st=pop(st);
    st=pop(st);
    cout << ">==>Is stack empty." << endl;
    if(isEmpty(st)) {
        cout << "Stack is empty" << endl;
    }
    return 0;
}