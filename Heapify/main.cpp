#include<iostream>
using namespace std;

/*
    - Heapify: Heapify is the fastest way create a Binary Heap.
        - Start from Right to Left
        - Not going to use 0th index
*/

void swap(int A[], int i, int j) {
     int temp = A[i];
     A[i] = A[j];
     A[j] = temp;
}

void print(int A[], int n) {
    for(int i = 1; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Heapify(int A[], int size) {
    //we start from last children
    int i = size-1;
    int j; //left children because index is starting
    while(i > 0) {
        //find greatest children
        //means a valid j 
        j = 2*i;
        if(j+1 < size) {
            if(A[j+1] > A[j]) {
                j = j + 1;
            }
            if(A[i] < A[j]) {
                swap(A, i, j);
            }
        }
        i--;
    }
}

int main() {
    int A[] = {0, 5,10,30,20,35,40,15};
    Heapify(A, 8);
    print(A, 8);
    int B[] = {0,5,10,30,20};
    Heapify(B, 5);
    print(B, 5);
}

