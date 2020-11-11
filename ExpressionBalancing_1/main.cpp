#include<iostream>
#include<cstring>
using namespace std;

// AS we representing stack as a linked list
/*
 - we will always insert or delete node from head
*/

struct Node {
    char data;
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
Node* push(Node* top, char x) {
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

int stackTop(Node* top) {
    if(!top) {
        cout << "Stack Underflow, can't pop." << endl;
        return 0;
    }
    return top->data;
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


bool isBalanced(const char* exp) {
    //first i would like to creat a stack where to store the incoming expression stream
    //size of stack I will take to length of expression.
    /*
    Algo:
        1. Create a stack
        2. If incoming char is '(' push on to stack
        3. if incoming char is ')' then stack's TOP must have '('
        4. If stack is found to be empty then immediately returned not balanced.
        5. If expression finished but stack is not empty 
    */
    Node* stk=0;
    for(int i=0;exp[i]!='\0';i++) {
        //iterating over string
        if(exp[i]=='(') {
            stk=push(stk, exp[i]);
        } else if(exp[i] == ')') {
            if(isEmpty(stk)) return false;
            stk=pop(stk);
        }
    }
    //if expression is balanced then stack must be empty at this point of time.
    if(isEmpty(stk)) return true;
    return false;;
}

int main() {
    const char* exp = "((a+b*(c-d))";
    isBalanced(exp) ? (cout << "Expression is balanced.\n"):(cout<<"Expression is not balanced.\n");
    return 0;
}