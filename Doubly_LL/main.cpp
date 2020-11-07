#include <iostream>

using namespace std;

/*
Doubly Linked List
*/

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* create(int A[], int n);
void display_iterative(Node*);
void display_recursive(Node*);
Node* insert_last(Node*, int);
Node* insert_at(Node*, int, int);
Node* delete_at(Node*, int);
Node* reverse(Node*);

/*
    Functions Here
*/

void display_iterative(Node* ptr) {
    if(!ptr) return;
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void display_recursive(Node* ptr) {
    if(!ptr) return;
    cout << ptr->data << " ";
    display_recursive(ptr->next);
}

Node* create_using_array(int A[], int n) {
    Node* head = new Node;
    head->data = A[0];
    head->next = 0;
    head->prev = 0;

    Node* t;
    Node* last = head;

    for(int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
    return head;
}

Node* insert_last(Node* ptr, int val) {
    Node* t = new Node;
    t->data = val;
    t->next = 0;
    if(!ptr) {
        //means DLL is empty
        t->prev = 0;
        ptr = t;
    } else {
        Node* p = ptr;
        while(p->next != 0) {
            p = p->next;
        }
        p->next = t;
        t->prev = p;
        p = t;
    }
    return ptr;
}

Node* insert_at(Node* ptr, int pos, int val) {
    Node* node = new Node;
    node->data = val;
    if(pos==0 || pos == 1) {
        node->prev = 0;
        if(!ptr) {
            node->next = NULL;
            ptr=node;
        } else {
            node->next = ptr;
            ptr->prev = node;
            ptr = node; 
        }
    } else {
        Node* p = ptr;
        for(int i= 0;i<pos-1 && p;i++) {
            p = p->next;
        }
        if(!p) {
            cout << "Invalid index supplied." << endl;
            return ptr;
        }
        node->next = p->next;
        node->prev = p;
        //only if it is a middle element
        if(p->next) {
            p->next->prev = node;
        }
        p->next = node;
    }
    return ptr;
}

Node* delete_at(Node* ptr, int pos) {
    Node* p = ptr;
    if(!ptr) return nullptr;
    if(pos==0 || pos == 1) {
        //check if list is null
        ptr = ptr->next;
        if(ptr) {
            ptr->prev = 0;
        }
        cout << "Node with value " << p->data << " deleted." << endl;
        p = 0;
    } else {
        //because in deleting we are stopping one node before the delete. Therefore checking for ptr->next !=0
        for(int i=0;i<pos-2 && p->next;i++) {
            p=p->next;
        }
        if(!p->next) {
            cout << "Invalid index is given" << endl;
            return ptr;
        }
        Node* q = p->next;
        p->next = q->next;
        if(q->next) {
            q->next->prev = p;
        }
        cout << "Node with value " << q->data << " deleted." << endl;
        q=0;
    }
    return ptr;
}

Node* reverse(Node* ptr) {
    /*
        Algo:
            - You will swap VISITING node's pointers with previous and next
            - you will move ahead in the list using previous pointers
            - you will move the head of the LL to the last visite node.
    */
   if(!ptr) return nullptr;
   Node* p = ptr;
   Node* temp;
   while(p) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        //Although only P->next==0 would have been the case BUT checking for P handles for the case when there is only one node.
        if(p && p->next == 0) {
            //means now we wre at last node;
            ptr = p;
        }
   }
   return ptr;
}

int main() {
    int A[10] = {3, 9, 11, 13, 19, 21, 24, 47, 59, 61};
    Node* L1 = 0;
    cout << ">==>Creating Doubly Linked List using Array" << endl;
    L1 = create_using_array(A, 10);
    cout << ">==>Displaying DLL - Iterative." << endl;
    display_iterative(L1);
    cout << ">==>Displaying DLL - Recursive." << endl;
    display_recursive(L1);
    cout << endl;
    cout << "Creating DLL using Insert AT GIVEN INDEX." << endl;
    Node* L2 = 0;
    L2 = insert_at(L2, 0, 20);
    L2 = insert_at(L2, 1, 30);
    L2 = insert_at(L2, 2, 50);
    L2 = insert_at(L2, 3, 60);
    L2 = insert_at(L2, 2, 40);
    L2 = insert_at(L2, 0, 10);
    display_recursive(L2);
    cout << endl;
    cout << "Creating DLL by inserting AT LAST position." << endl;
    L2 = insert_last(L2, 70);
    L2 = insert_last(L2, 80);
    display_iterative(L2);

    cout <<"Deleting element by index." << endl;
    L2=delete_at(L2, 2);
    display_iterative(L2);

    L2 = reverse(L2);
    display_iterative(L2);
    return 0;
}