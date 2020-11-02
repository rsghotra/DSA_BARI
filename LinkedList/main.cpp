#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//make it global so that every function can have access to it.
Node* first=NULL;
Node* last=NULL;

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

int length_iterative(Node* ptr) {
    int count = 0;
    while(ptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int length_recursive(Node* ptr) {
    if(ptr==0) {
        return 0;
    }
    return 1 + length_recursive(ptr->next);
}

int sum_iterative(Node* ptr) {
    int sum = 0;
    while(ptr) {
        sum += ptr->data;
        ptr=ptr->next;
    }
    return sum;
}

int sum_recursive(Node* ptr) {
    if(ptr == 0) return 0;
    else return sum_recursive(ptr->next) + ptr->data;
}

int max_iterative(Node* ptr) {
    int max = -32567;
    while(ptr) {
        if(ptr->data > max) {
            max = ptr->data;
        }
        ptr=ptr->next;
    }
    return max;
}

//watch out - head recursion
int max_recursive(Node* ptr) {
    //Freaking HEAD recursion
    int x = 0;
    if(ptr==0) return x;
    else {
        x = max_recursive(ptr->next);
        if(ptr->data > x) {
            return ptr->data;
        }
    }
    return x;
}

Node* search_iterative_move_head(Node* ptr, int key) {
    if(ptr==0) return NULL;
    //when element is present at head then while loops' logic breaks down.
    if(ptr->data == key) return ptr;
    Node* tail = ptr;
    while(ptr) {
        if(ptr->data == key) {
            cout << "Element found. ";
            tail->next = ptr->next;
            ptr->next=first;
            first = ptr;
            return ptr;
        }
        tail = ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

Node* search_recursive(Node* ptr, int key) {
    //if you are searching then the terminative condition will have successul case as well
    if(ptr==0)  {
        cout << "Element not found. ";
        return nullptr;
    }
    if(ptr->data == key) {
        cout << "Element found. ";
        return ptr;
    }
    search_recursive(ptr->next, key);
}

Node* search_iterative(Node* ptr, int key) {
    while(ptr) {
        if(ptr->data == key) {
            cout << "Element found. ";
            return ptr;
        }
        ptr = ptr->next;
    }
    cout << "Element not found. ";
    return nullptr;
}

void insert_after(Node* ptr, int pos, int k) {
    //we need to handle insert at 0 sepratrely
    if(pos >= 0) {
        Node* tmp;
        tmp->data = k;
        if(pos==0) {
            cout << "Inserting at HEAD." << endl;
            tmp->next = first;
            first = tmp;
        } else {
            //ptr is pointing to temp
            for(int i=0;i<pos-1 && ptr != 0;i++) {
                ptr = ptr->next;
            }
            //means a valid index
            if(ptr) {
                tmp->next = ptr->next;
                ptr->next = tmp;
            } else {
                cout << "In-valid index supplied." << endl;
            }
        }
    } else{
        cout << "Negative index supplied."<<endl;
    }
}

void insert_last(int val) {
    //create node
    Node* temp = new Node();
    temp->data = val;
    temp->next = 0;

    //NODE IS CREATED MUST FIRST HANDLE WHEN THERE IS NO NODE AND ITITIATE THE POINTER THERE AFTER
    if(first == 0) {
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

int main() {
    int A[] = {13,7,5,9,11,16};
    create(A,6);
    display_iterative(first);
    cout << "Displaying - Recursive." << endl;
    display_recursive(first);
    cout << endl;
    cout << "Displaying - Reverse - Recursive." << endl;
    display_reverse_recursive(first);
    cout << endl;
    
    cout << "Length - Iterative. " << length_iterative(first) << endl;
    cout << "Length - Recursive. " << length_recursive(first) << endl;

    cout << "Sum - Iterative. " << sum_iterative(first) << endl;
    cout << "Sum - Recursive. " << sum_recursive(first) << endl;

    cout << "Max - Iterative. " << max_iterative(first) << endl;
    cout << "Max - Recursive. " << max_recursive(first) << endl;

    cout << "Search - Iterative. " << search_iterative(first, 13) << endl;
    cout << "Search - Recursive. " << search_recursive(first, 7) << endl;
    cout << "Search - Iterative - Move First. " << search_iterative_move_head(first, 16) << endl;
    display_recursive(first);
    cout << endl;
    cout << "Insert After - Iterative. " << endl;
    insert_after(first, 2, 17);
    display_recursive(first);

    cout << "\nCreating a Linked List by inserting at last every time" << endl;
    first = 0;
    insert_last(30);
    insert_last(7);
    insert_last(13);
    insert_last(19);
    insert_last(11);
    display_recursive(first);

    return 0;
}