#include<iostream>
using namespace std;

/*
    -Array representation of Stack
    -Three thing are needed
        -Top
        -Size
        -Storage - Array
    - Remember: All operations: push, pop, peek etc all takes constant time
    - Inserting from right hand side.

*/

struct Stack{
    int top;
    int size;
    int* A;
};

void push(Stack*, int x);
int pop(Stack);
bool is_full(Stack);
bool isEmpty(Stack);
int peek(Stack, int);
int get_top(Stack);
void display(Stack);


bool is_full(Stack st) {
    bool status = false;
    if(st.top == st.size-1) status = true;
    else status = false;
    return status;
}


bool isEmpty(Stack st) {
    if(st.top == -1) return true;
    else return false;
}

int get_top(Stack st) {
    if(st.top == -1) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return st.top;
}

void display(Stack st) {
    if(st.top == -1) {
        cout << "Stack is empty. Nothing to display." << endl;
        return;
    }
    for(int i = st.top; i >=0;i--) {
        cout << st.A[i] << " ";
    }
    cout << endl;
}

void push(Stack* st, int x) {
    if(st->top== st->size-1) {
        cout << "Stack is full. Can not push" << endl;
        return;
    } else {
        st->top++;
        st->A[st->top] = x;
    }
}

int pop(Stack* st) {
    int x = -1;
    if(st->top == -1) {
        cout << "Stack Underflow. Can not pop" << " ";
        return -1;
    } else {
        x = st->A[st->top];
        st->top--;
    }
    return x;
}

int peek(Stack st, int pos) {
    if(st.top == -1) {
        cout << "Stack is empty.Nothing to be peeked." << endl;
        return -1;
    }
    if(st.top - pos + 1 < 0) {
        cout << "Invalid position is given to peek" << endl;
        return -1;
    }
    return st.A[st.top - pos + 1];
}

int main() {
    Stack st; //initialize stack with base values;
    cout << "How many elements in the stack?" << endl;
    cin >> st.size;
    st.top = -1;
    st.A = new int[st.size];

    cout << ">==>Pushing elements to stack." << endl;
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    push(&st, 70);
    push(&st, 80);
    push(&st, 90);
    push(&st, 100);
    cout << ">==>Displaying elements of stack." << endl;
    display(st);
    cout << ">==>Is stack full." << endl;
    if(isEmpty(st)) {
        cout << "Stack is full." << endl;
    }
    cout << ">==>Popping elements." << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << ">==>Is stack empty." << endl;
    if(isEmpty(st)) {
        cout << "Stack is empty" << endl;
    }
    return 0;
}