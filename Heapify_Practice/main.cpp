#include<iostream>
using namespace std;

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


void Heapify(int H[], int n) {

    //kind of same procedure will be followed as of deleting a Max Heap
    //Except we move from right to left
    int j;
    for(int i{n-1}; i > 0; --i) {
        j = 2 * i;
        if(j+1 < n) {
            //i can proceed with same stuff as there is space in heap
            //select the largest kid
            if(H[j+1] > H[j]) {
                j = j+1;
            }
            if(H[j] > H[i]) {
                swap(H[i], H[j]);
            }
        }
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