#include<iostream>
#include<vector>
using namespace std;

//Please note that we do not USE array index 1 for Heap implementation
//Heap is implemented using array
/*
    - Operations available to Heap:
        - Create heap by inserting one element at a time - Bottom - Up approach
*/

//n = index of the element where new value and present and need adjustment
//n represent current Heap Size
void insert(vector<int>& A, int n) {
    int x = A[n]; //value to be inserted in heap and adjusted
    int i = n;
    while(i > 1 && x > A.at(i/2)) {
        A.at(i) = A.at(i/2);
        i = i/2;
    }
    A.at(i) = x;
}

void swap(int& x, int& y) {
    int temp = y;
    y = x;
    x = temp;
}

void Delete(vector<int>& A, int n) {
    int x = A[1];//last element to be replaced
    A[1] = A[n];
    int i = 1;
    int j = 2* i;
    int temp;
    // j is forward pointer
    while( j < n) 
    {
        //finalize the successor
        if(A[j+1] > A[j]) {
            j = j+1;
        }
        if(A[j] > A[i]) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
    A[n] = x;
}

int main() {
    //not using first location
    //MAX - HEAP
    vector<int> A{0, 5, 10,30,20,35,40,15};
    //we will consider first element of the array already in heap
    //we will send insert request from 1
    cout << "\nPrinting Given Array: " << endl;
    for(size_t j{1}; j < A.size(); ++j) {
        cout << A.at(j) << " ";
    }
    for(size_t i{2}; i < A.size(); ++i) {
        insert(A, i);
    }

    cout << "\nPrinting Max Heap: " << endl;
    for(size_t j{1}; j < A.size(); ++j) {
        cout << A.at(j) << " ";
    }

    cout <<"\nHeap Sort - Deleting All Elements in Max Heap" << endl;
    for(size_t i{A.size() - 1}; i >= 1; --i) {
        Delete(A, i);
    }

    cout << "\nPrinting Sorted Array: " << endl;
    for(size_t j{1}; j < A.size(); ++j) {
        cout << A.at(j) << " ";
    }

}