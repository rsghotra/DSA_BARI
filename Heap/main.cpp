#include<iostream>
#include<vector>
using namespace std;

/*
    - CONCEPT: Binary Heap Implementation Using Array
        1. Binary Heap is a Complete Binary Tree
        2. Because it is a complete Binary Tree: Max and Min Height are both logarithmic
        3. Every Node value must be greater or equal to all its descendantds.
        4. Two Variations: Max Heap and Min Heap
        5. As it is NOT a BST - Duplicates are allowed
        6. Array INDEX must START FROM 1.
        7. Create HEAP: o(nlogn)
        8. Inserting a Single Element: o(h) == o(logn)
*/

void Insert(int A[], int index) {
    //index is the first element outside of heap
    //element to be inserted will be the supplied index element
    int temp = A[index];
    int i = index;
    //keep going until child is bigger than parent or array is not finished
    //careful i must start from greater than 1 becuase at the end of while loop. if the
    //incoming element is indeed the largest element - we do not want to traverse until the end
    while(i > 1 && temp > A[i/2]) {
        //switch places
        A[i] = A[i/2];
        i = i/2;
    }
    //at this point right place is found
    A[i] = temp;
}


void Insert_V(vector<int>& vec, int key) {
    auto i = vec.size();
    vec.emplace_back(key);

    //Rearrange element o(logn)
    while(i > 1 && key > vec[i/2]) {
        vec[i] = vec[i/2];
        i = i/2;
    }
    vec[i] = key;
}

void CreateHeap_V(vector<int>& vec, int A[], int n) {
    //O(nlogn)
    for(int i = 0; i< n;i++) {
        Insert_V(vec, A[i]);
    }
}

void print(int A[], int n) {
    for(int i = 1; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void print(vector<int> vect) {
    for(int i = 1; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    //Index 0 - DISCARDING
    //Index 1 - is the first element of HEAP
    int i = 2;
    for(i; i <=7; i++) {
        Insert(A, i);
    }
    print(A, 8);
    vector<int> v;
    CreateHeap_V(v, A, 8);
    print(v);
}