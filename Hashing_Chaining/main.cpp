#include<iostream>
#define SIZE 10
using namespace std;

/*
    ==> Open Hashing Techniquw - Chaining
    - Important Points
        - Infinited Hash Table Size
        - H(x) = x%size;
        - Avg successful search = 1+lambda/2
        - Avg Unsuccessful search = 1 + lambda
        - Load Factor > 1
        - Number of elements = 100
        - Hash table size = 10
*/

class Node {
    public:
        int data;
        Node* next;
};

class HashTable {
    public:
        //Just lile int* Q[]
        Node** HT;
        HashTable();
        int Hash(int key);
        void Insert(int key);
        int Search(int key);
        ~HashTable();
        void print(); 
};

void HashTable::print() {
    Node* p = 0;
    if(HT != 0) {
        for(int i = 0 ; i < SIZE; i++) {
            p = HT[i];
            if(p == 0) cout << "XXXXX" << " ";
            while(p != 0) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

HashTable::HashTable() {
    HT = new Node*[SIZE];
    for(int i = 0; i < SIZE; i++) {
        HT[i] = 0;
    }
}

HashTable::~HashTable() {
	for (int i=0; i<SIZE; i++){
		Node* p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

int HashTable::Hash(int key) {
    return key%SIZE;
}

int HashTable::Search(int key) {
    int index = Hash(key);
    if(HT[index]) {
        Node* ptr = HT[index];
        while(ptr) {
            if(ptr->data == key) {
                return ptr->data;
            }
            ptr = ptr->next;
        }
    }
    return -1;
}

void HashTable::Insert(int key) {
    int index = Hash(key);
    Node* temp = new Node;
    temp->data = key;
    temp->next = 0;

    if(HT[index] == nullptr) {//spot is empty 
        HT[index] = temp;
    }else {
        Node* ptr = HT[index];
        Node* qtr = 0;
        //handling head insertion
        if(ptr->data > key) {
            temp->next = ptr;
            ptr = temp;
            HT[index] = temp;
        } else {
            while(ptr && ptr->data < key) {
                qtr = ptr;
                ptr = ptr->next;
            }
            temp->next = qtr->next;
            qtr->next = temp;
        }
    }
}

int main() {
    int A[9] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    HashTable HT;

    for(int i = 0; i < 9; i++) {
        HT.Insert(A[i]);
    }

    HT.print();

    cout << "Successful Search" << endl;
	int key = 6;
	int value = HT.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = HT.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
    return 0;
}