#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display_iterative(Node*);
void display_recursive(Node*, Node*);
Node* create_cll_array(int[], int);
Node* insert_at(Node*, int, int);
Node* insert_last(Node*, int);
Node* delete_at(Node*, int);

//==> Functions starts here

Node* create_cll_array(int A[], int n) {
    //initialise the list by creating one node.
    Node* head = new Node;
    head->data = A[0];
    head->next = head;
    Node* last = head;
    Node* t;
    for(int i=1;i<n;i++) {
        t = new Node;
        t->data = A[i];
        last->next = t;
        last = t;
        t->next = head;
    }
    return head;
}

void display_iterative(Node* ptr) {
    if(!ptr) return;
    Node* p = ptr;
    do{
        cout << p->data << " ";
        p = p->next;
    } while(p!=ptr);
    cout << endl;
}

void display_recursive(Node* ptr, Node* head) {
    //a little tricky because of do-while kind of functionality
    if(!ptr) return;
    static int flag = 0;
    if(flag == 0 || ptr != head) {
        flag = 1;
        cout << ptr->data << " ";
        display_recursive(ptr->next, head);
    }
}

Node* insert_last(Node* ptr, int val) {
    //this algo will always insert the node
    Node* node = new Node;
    node->data = val;
    if(!ptr) {
        ptr = node;
    } else {
        Node* pqr = ptr;
        while(pqr->next != ptr) {
            pqr = pqr->next;
        }
        pqr->next = node;
    }
    node->next = ptr;
    return ptr;
}

Node* insert_at(Node* ptr, int pos, int val) {
    Node* pqr = ptr;
    Node* node = new Node;
    node->data = val;
    if(pos==1) {
        //insert at head
        if(!ptr) {
            //empty list
            ptr = node;
            node->next = ptr;
        } else {
            node->next = ptr;
            while(pqr->next != ptr) {
                pqr = pqr->next;
            }
            pqr->next = node;
            ptr = node;
        }
    } else {
        //possiblity that index is not good
        int flag = 0;
        for(int i=0;(i<pos-1 && pqr!=ptr)||flag == 0;i++) {
            flag = 1;
            pqr = pqr->next;
        }
        if(pqr == ptr) {
            cout << "Invalid index supplied." << endl;
            return ptr;
        } else {
            node->next = pqr->next;
            pqr->next = node;
        }
    }
    return ptr;
}

/*
    Delete from
*/
Node* delete_from(Node* ptr, int pos) {
    //delete ke liye ek node se ek pehle phunchna hai-so pos-2 and similarly algo changes accordingly
    Node* pqr = ptr;
    if(!ptr) return nullptr;
    if(pos==1) {
        if(ptr->next == ptr) {
            //single node circular LL
            cout << "Node with value: " << ptr->data << "has been removed." << endl;
            ptr = 0;
            return ptr;
        }
        while(pqr->next!=ptr) {
            pqr = pqr->next;
        }
        pqr->next = ptr->next;
        ptr=0;
        ptr = pqr->next;
    } else {
        for(int i=0;(i<pos-2 && pqr->next!=ptr);i++) {
            pqr = pqr->next;
        }
        if(pqr->next == ptr) {
            cout << "Invalid index supplied for deletion" << endl;
            return ptr;
        } else {
            //check if the node to be deleted is the last node
            Node* q = pqr->next;
            pqr->next = q->next;
            cout << "Node with value: " << q->data << " has been removed." << endl;
            q=0;
        }
    }
    return ptr;
}


int main() {
    int A[10] = {3, 9, 11, 13, 19, 21, 24, 47, 59, 61};
    cout << ">==>Creating circular ll using array." << endl;
    Node* L1 = create_cll_array(A, 10);
    display_iterative(L1);
    cout << ">==>Displaying the list recursively." << endl;
    display_recursive(L1, L1);
    cout << endl;
    cout << ">==>Creating a circular LL by always inserting the node at last" << endl;
    Node* L2 = 0;
    L2 = insert_last(L2, 9);
    display_recursive(L2, L2);
    L2 = insert_last(L2, 10);
    L2 = insert_last(L2, 20);
    L2 = insert_last(L2, 30);
    L2 = insert_last(L2, 40);
    L2 = insert_last(L2, 50);
    L2 = insert_last(L2, 60);
    display_iterative(L2);

    cout << "<==>Demonstrating inserting at any index functionality" << endl;
    L2 = insert_at(L2,7,15);
    display_iterative(L2);

    Node* L3 = 0;
    L3 = insert_at(L3, 1, 1);
    L3 = insert_at(L3, 1, 4);
    L3 = insert_at(L3, 2, 8);
    L3 = insert_at(L3, 3, 18);
    display_iterative(L3);

    L3 = delete_from(L3, 3);
    display_iterative(L3);
    return 0;
}