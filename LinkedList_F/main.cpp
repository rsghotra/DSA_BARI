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

/*
    Fourth Tukdi
*/
bool is_sorted(Node*);
Node* delete_at(Node*, int);
Node* insert_at(Node*, int, int);
void remove_duplicates(Node*);
/*

/*
    Fifth Tukdi
        - Reverse Linked List Using Sliding Pointer Algorithm
        - Reverse Linked List Using Recursion
        - Concatenate Two LL
        - Merge two Sorted Linked List
*/
//=====>Functions STARTS BELOW


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

/*
    - IS LIST SORTED
*/

bool is_sorted(Node* ptr) {
    int x = -32000;
    if(!ptr) return true;
    while(ptr) {
        if(ptr->data < x) return false;
        x = ptr->data;
        ptr = ptr->next;
    }
    return true;
}

/*
    DELETE an element from a given position.
*/

Node* delete_at(Node* ptr, int pos) {
    int x;
    if(ptr == 0) {
        cout << "Linked List supplied was empty." << endl;
        return nullptr;
    }
    if(pos == 1) {
        //Deleting head is a special case
        Node* p = ptr;
        ptr = ptr->next;
        delete p;
    } else {
        Node* p = ptr;
        Node* q = 0;
        for(int i=0;i<pos-1 && p;i++) {
            q = p;
            p = p->next;
        }
        if(!p) {
            cout << "Invalid Index is given." << endl;
            return ptr;
        } else {
            q->next = p->next;
            delete p;
        }
    }
    return ptr;
}

/*
    - REMOVE DUPLICATES FROM A SORTED LINE
*/

void remove_duplicates(Node* ptr) {
    if(!ptr) return;
    if(ptr->next == 0) return;
    //to avoid the null's next check
    //now i know there are atleast two nodes in th list
    Node *p = ptr->next;
    Node* q = ptr;
    while(p) {
        if(q->data == p->data) {
            q->next = p->next;
            delete p;
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
    }
}

Node* reverse_using_sliding_ptrs(Node* ptr) {
    Node* head = 0;
    if(!ptr) return head;
    if(!ptr->next) return ptr;

    //Seed values are important
    //Interesting use of three pointers
    Node* p = ptr;
    Node* q = 0;
    Node* r = 0;

    //reversing of links will happen  on Q.
    while(p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    //Now set set head to Q;
    head = q;
    return head;
}

Node* head;
void Reverse_Recursive(Node* p, Node* q) {
    //q is following p 
    if(p) {
        Reverse_Recursive(p, p->next);
        p->next = q;
    } else {
        head = q;
    }
}

Node* concat(Node* L1, Node* L2) {
    if(L1 == 0 && L2 != 0) return L2;
    if(L2 == 0 && L1 != 0) return L1;
    if(L1 == 0 && L1 == 0) return nullptr;
    Node* t = L1;
    while(t->next != 0) {
        t = t->next;
    }
    t->next = L2;
    L2 = 0;
    return L1;
}

Node* merge_sorted(Node* L1, Node* L2) {
    if(L1 == 0 && L2 != 0) return L2;
    if(L2 == 0 && L1 != 0) return L1;
    if(L1 == 0 && L1 == 0) return nullptr;

    //Using two pointers
    Node* third;
    Node* last;
    if(L1->data < L2->data) {
        third = L1;
        last = L1;
        L1 = L1->next;
    } else {
        third = L2;
        last = L2;
        L2=L2->next;
    }
    //Node the head is initialized properly
    while(L1 && L2) {
        if(L1->data <L2->data) {
            last->next = L1;
            last = L1;
            L1 = L1->next;
        } else {
            last->next = L2;
            last = L2;
            L2 = L2->next;
        }
    }
    //at this time one of list is exhausted
    if(L1) {
        last->next = L1;
    }
    if(L2) {
        last->next = L2;
    }
    return third;
}

bool isLoop(Node* ptr) {
    if(!ptr) return false;
    if(!ptr->next) return false;
    Node* p = ptr;
    Node* q = ptr;
    do{
        q = q->next;
        p = p->next;
        p = p ? p->next : p; 
    }while(p && q && p != q);
    if(p==q) return true;
    else return false;
}

int find_middle(Node* ptr) {
    if(!ptr) return -1;
    if(!ptr->next) return ptr->data;
    Node* p = ptr;
    Node* q = ptr;
    while(p) {
        p = p->next;
        q = q->next;
        if(p) {
            p = p->next;
        }
    }
    return q->data;
}

/*
    Check for Loop
*/
Node* make_loop(Node* ptr) {
    Node* p = ptr->next->next->next->next;
    Node* q = ptr;
    while(q->next) {
        q = q->next;
    }
    q->next = p;
    return ptr;
}

bool is_loop(Node* ptr) {
    Node* p = ptr;
    Node* q = ptr;

    if(!ptr) return false;
    do {
        q = q->next;
        p = p->next;
        if(p) {
            p = p->next;
        }
    } while(p!= 0 && p != q);
    if(p == q) return true;
    if(!p) return false;
}

int main() {
    int A[10] = {3, 9, 11, 13, 19, 21, 24, 47, 59, 61};
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
    L2 = insert_at_last(L2, 2);
    L2 = insert_at_last(L2, 2);
    L2 = insert_at_last(L2, 3);
    L2 = insert_at_last(L2, 3);
    L2 = insert_at_last(L2, 4);
    L2 = insert_at_last(L2, 4);
    L2 = insert_at_last(L2, 99);
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
    
    cout << ">==>Checking if LL is sorted." << endl;
    is_sorted(L2) == true ? (cout << "Linked List is sorted." << endl) : (cout << "Linked List is not sorted." << endl);
    display_I(L2);

    cout << ">==>Deleting Node from a given position." << endl;
    L1 = delete_at(L1, 11);
    L1 = delete_at(L1, 1);
    L1 = delete_at(L1, 3);
    display_I(L1);

    cout << ">==>Removing duplicates from a sorted linked list." <<endl;
    remove_duplicates(L2);
    display_I(L2);
    /*
    Fifth Tukdi
        - Reverse Linked List Using Sliding Pointer Algorithm
        - Reverse Linked List Using Recursion
        - Concatenate Two LL
        - Merge two Sorted Linked List
    */
    cout << "Reversing using sliding pointers" << endl;
    display_I(L1);
    L1 = reverse_using_sliding_ptrs(L1);
    L1 = reverse_using_sliding_ptrs(L1);
    display_I(L1);

    // cout << "Reversing LL using Recursion" << endl;
    // Reverse_Recursive(L1, L1->next);
    // display_I(head);

    cout << ">==>Merging two sorted LL." << endl;
    display_I(L1);
    display_I(L2);
    Node* L3 = merge_sorted(L1, L2);
    display_I(L3);

    // cout << ">==>Concatenating Two Lists." << endl;
    // L1 = concat(L1, L2);
    // display_I(L1);
   /*
    Algo Tukdi
        - Finding Middle Element
        - Check if LL has a loop
        - Finding Intersection
        - Polynomial represenatation
        - Sparse Matrix: Representation, Creation, Display, Add
    */
    cout << "Displaying middle element of a given LL" << endl;
    display_I(L1);
    cout << find_middle(L1) << endl;
    cout << "Checking if a LL has loop" << endl;
    isLoop(L1) ? (cout << "LL contains loop.") : (cout << "LL does not contain loop.");
    cout << endl;
    L1 = make_loop(L1);
    isLoop(L1) ? (cout << "LL contains loop.") : (cout << "LL does not contain loop.");
    cout << endl;
    return 0;
}