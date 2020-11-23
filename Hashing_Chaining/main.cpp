#include <iostream>
#include "Chains.h"

using namespace std;



struct Node {
    Node* next;
    int data;
};

int hash(int key) {
    return key%10;
}

Node* Search(Node* ptr, int key) {
    if(ptr==0) return nullptr;
    while(ptr) {
        if(ptr->data == key)
            return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}
// void Delete(Node* ptr, int key) {
//     int x;
//     Node* p = 0;
//     if(ptr == 0) {
//         return;
//     }
//     if(ptr->data == key) {
//         //Deleting head is a special case
//         p= ptr;
//         ptr = ptr->next;
//         if(p == root) {
//             root == ptr;
//         }
//         delete p;
//     } else {
//         p = ptr;
//         Node* q = 0;
//         while(p->next->data != key) {
//             q = p;
//             p = p->next;
//         }
//         if(!p) {
//             return;
//         } else {
//             q->next = p->next;
//             delete p;
//         }
//     }
// }

void SortedInsert(Node** HT, int key) {
	int hIdx = ::hash(key);
	Node* t = new Node;
	t->data = key;
	t->next = nullptr;
	// Case: No nodes in the linked list
	if (HT[hIdx] == nullptr){
		HT[hIdx] = t;
	} else {
		Node* p = HT[hIdx];
		Node *q=HT[hIdx];
		// Traverse to find insert position
		while (p && p->data < key){
			q=p;
			p = p->next;
		}
		// Case: insert position is first
		if (q == HT[hIdx]){
			t->next = HT[hIdx];
			HT[hIdx] = t;
		} else {
			t->next = q->next;
			q->next = t;
		}
	}
}

void Insert(Node* H[], int key) {
    //getting index //using scope resolution to remove ambiguity
    int index = ::hash(key);

    //insert in a sorted linked list location
    SortedInsert(&H[index], key);

}

int main() {
    //create a Hash Table and initialize it
    Node* HT[10];
    int i;

    for(i=0; i< 10; i++) {
        HT[i] = 0;
    }

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    return 0;
}