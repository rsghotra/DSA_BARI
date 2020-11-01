#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//make it global so that every function can have access to it.
Node* first=NULL;

void create(int A[], int n) {
    int i;
    Node* t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    //rest i will create using for loop
    for(int i=1;i<n;i++) {
        //node is created
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display_iterative(Node* ptr) {
    cout << "Displaying - Iterative." << endl;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

/*
Number of Call = n+1
Stack Space = n+1
*/

//Tail Recursion
void display_recursive(Node* ptr) {
    if(ptr != 0) {
        cout << ptr->data << " ";
        display_recursive(ptr->next);
    }
}

//Head Recursion
void display_reverse_recursive(Node* ptr) {
    if(ptr != 0) {
        display_recursive(ptr->next);
        cout << ptr->data << " ";
    }
}

int main() {
    int A[] = {13,7,5,9,11};
    create(A, 5);
    display_iterative(first);
    cout << "Displaying - Recursive." << endl;
    display_recursive(first);
    cout << endl;
    cout << "Displaying - Reverse - Recursive." << endl;
    display_reverse_recursive(first);
    cout << endl;
    return 0;
}