#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//First Tukdi
void display_I(Node*);
void display_R(Node*);
void display_reverse(Node*);
Node* create_ll_by_array(int [], int);

/*
    Second Tukdi:
*/
int length_iterative(Node*);
int length_recursive(Node*);
int sum_iterative(Node*);
int sum_recursive(Node*);
int max_iterative(Node*);
int max_recursive(Node*);

/*
    Third Tukdi
*/

Node* l_search_move_head(Node*, int);
Node* l_search_iterative(Node*, int);
Node* l_search_recursive(Node*, int);
Node* insert_at_last(Node*, int);
Node* insert_at(Node*, int, int);

/*
=====>Functions STARTS BELOW
*/

/*
    T(n) = O(n+1)
    Total Iterations = n+1
*/
void display_I(Node* ptr) {
    if(!ptr) return;
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

/*
    T(N) = (n+1)
    S(N) = (n+1)
    n elements - n+1 function calls
    Displaying the elements using TAIL RECURSION
*/

void display_R(Node* ptr) {
    if(ptr == 0) return;
    else {
        cout << ptr->data << " ";
        display_R(ptr->next);
    }
}

/*
    T(n) = (n+1)
    S(n) = (n+1) ; +1 for failed function call
    WE WILL USE HEAD RECURSION
*/

void display_reverse(Node* ptr) {
    if(ptr==0) return;

    if(ptr) {
        display_reverse(ptr->next);
        cout << ptr->data << " ";
    }
}

/*
T(n)=(n+1)
*/
int length_iterative(Node* ptr) {
    int length = 0;
    if(ptr==0) return length;
    while(ptr) {
        length++;
        ptr=ptr->next;
    }
    return length;
}

/*

*/
int length_recursive(Node* ptr) {
    if(ptr==0) return 0;
    else return 1 + length_recursive(ptr->next);
}

Node* create_ll_by_array(int A[], int n) {
    Node* head = new Node;
    head->data = A[0];
    head->next = 0;

    //==
    Node* last = head;
    Node* t;
    int i;
    for(i=1;i < n; i++) {
        t = new Node;
        t->data = A[i];t->next=0;
        last->next = t;
        last = t;
    }
    return head;
}

/*
 - Finding sum of all element of LL
*/

int sum_iterative(Node* ptr) {
    int sum=0;
    if(!ptr) return sum;
    while(ptr) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

int sum_recursive(Node* ptr) {
    if(ptr == 0) return 0;
    else return ptr->data + sum_recursive(ptr->next);
}

/*
    - Finding max of all elements of LL
*/
int max_iterative(Node* ptr) {
    int max = -66000;
    while(ptr) {
        if(ptr->data > max) max = ptr->data;
        ptr=ptr->next;
    }
    return max;
}

int max_recursive(Node* ptr) {
    static int max = -66000;
    if(ptr == 0) return max;
    else {
        if(ptr->data > max) max = ptr->data;
        max_recursive(ptr->next);
    }
}

/*
- Insert AT LAST

*/
Node* insert_at_last(Node* ptr, int val) {
    //creating node as a node will always be inserted
    Node* node = new Node;
    node->data = val;
    node->next = 0;
    //node is ready
    if(!ptr) {
        ptr = node;
    } else {
        Node* pqr = ptr;
        Node* tail = ptr;
        //tail will follow pqr
        while(pqr) {
            tail = pqr;
            pqr = pqr->next;
        }
        tail->next = node;
    }
    return ptr;
}

/*
Linear Search in LL
*/

Node* l_search_iterative(Node* ptr, int x) {
    if(ptr==0) return nullptr;
    while(ptr) {
        if(ptr->data == x)
            return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

Node* l_search_recursive(Node* ptr, int x) {
    if(ptr==0) return 0;
    if(ptr->data == x) return ptr;
    l_search_recursive(ptr->next, x);
}

Node* l_search_move_head(Node* ptr, int x) {
    Node* p = ptr;
    Node* q = ptr;
    if(p == 0) return nullptr;
    while(p) {
        if(p->data == x) {
            q->next = p->next;
            p->next = ptr;
            ptr = p;
            return ptr;
        }
        q = p;
        p = p->next;
    }
    return ptr;
}

Node* insert_at(Node* ptr, int pos, int x) {
    Node* node = new Node;
    node->data = x;
    node->next = 0;
    if(pos==1) {
        //special case - if freaking list is empty
        if(!ptr) {
            ptr = node;
        } else {
            node->next = ptr;
            ptr = node;
        }
    } else {
        //now the case could be that the asked position is just not there
        Node* p = ptr;
        for(int i=0; i<pos-1&&p;i++) {
            p = p->next;
        }
        if(!p) {
            cout << "Invalid index." << endl;
            return ptr;
        }
        node->next = p->next;
        p->next = node;
    }
    return ptr;
}

int main() {
    int A[10] = {22, 33, 11, 9, 99, 770, 10, 8, 18, 3};

    /*
        First Tukdi:
            - create linked list using array
            - display linked list using iteration
            - display linked list using recursion
            - reverse display linked list
    */
    Node* L1 = create_ll_by_array(A, 10);
    cout << "==>Displaying LL using Iteration now:"<<endl;
    display_I(L1);
    cout << "==>Displaying LL using Tail Recursion Now: " << endl;
    display_R(L1);
    cout << "Reverse Displaying LL using HEAD RECURSION NOW: " << endl;
    display_reverse(L1);
    cout << endl;

    /*
        Second Tukdi:
            - Length of LL using iteration
            - Length of LL using recursion
            - sum of all elements of linked list using iteration
            - sum of all element of linked list using recursion
            - max of all elements in LL using iteration
            - max of all elements in a LL using recursion
    */
    cout << "Extracting Length of LL using iteration: " << length_iterative(L1) << endl;
    cout << "Extracting Length of LL using recursion: " << length_recursive(L1) << endl;
    cout << "Sum of all elements of LL using iteration: " << sum_iterative(L1) << endl;
    cout << "Sum of all elements of LL using recursion: " << sum_recursive(L1) << endl;
    cout << "Max of all elements of LL using iteration " << max_iterative(L1) << endl;
    cout << "Max of all elements of LL using recursion " << max_iterative(L1) << endl;

    /*
        Third Tukdi
            - creating list by inserting at last
            - insert node at any given index
            - implement linear search in LL
            - implement transpose strategy to improve LL search operation
    */
    cout <<">==>Inserting element to Linked List: " << endl;
    Node* L2 = 0;
    L2 = insert_at_last(L2, 23);
    L2 = insert_at_last(L2, 26);
    display_I(L2);

    cout << ">==>Linear search - Iterative." << endl;
    l_search_iterative(L1, 77) == nullptr ? (cout << "Element not found in the list." << endl) : (cout << "Element found in the list." << endl);

    cout << ">==>Linear search - Recursive." << endl;
    l_search_recursive(L1, 770) == nullptr ? (cout << "Element not found in the list." << endl) : (cout << "Element found in the list." << endl);

    cout << ">==>Linear Search - Move to Head." << endl;
    L1 = l_search_move_head(L1, 9);
    display_I(L1);

    /*
        Fourth Tukdi
            - Insert in a sorted LL
            - Check if LL is sorted
            - Delete Node from any given position
            - Remove Duplicated From LL
    */
   cout << ">==>Inserting at any given position." << endl;
   L1 = insert_at(L1, 10, 20);
   display_I(L1);
    return 0;
}