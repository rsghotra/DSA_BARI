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

// void Insert(int A[], int index) {
//     //index is the first element outside of heap
//     //element to be inserted will be the supplied index element
//     int temp = A[index];
//     int i = index;
//     //keep going until child is bigger than parent or array is not finished
//     //careful i must start from greater than 1 becuase at the end of while loop. if the
//     //incoming element is indeed the largest element - we do not want to traverse until the end
//     while(i > 1 && temp > A[i/2]) {
//         //switch places
//         A[i] = A[i/2];
//         i = i/2;
//     }
//     //at this point right place is found
//     A[i] = temp;
// }

void Insert(int H[], int heapSizePlusOneIndex) {
    //for insert we check for parents
    int element = H[heapSizePlusOneIndex];
    int i = heapSizePlusOneIndex;
    //i one tak jae
    while( i > 1 && element > H[i/2]) {
        H[i] = H[i/2];
        i = i/2;
    }
    //self copy will happen if nothing changes from while loop
    //Else for the case when incoming is the max element
    H[i] = element;
}

int Delete(int H[], int currHeapSizeIndex) {
    /*
        We can only delete the root element
    */
    int temp;
    int val = H[1];
    
    //copying the last element to first element
    H[1] = H[currHeapSizeIndex];

    //rearrangement with the kids
    int i = 1;
    int j = 2*i;

    //because j is the forward pointer - hence termination will be dependent upon this
    while(j < currHeapSizeIndex - 1) {
        //find appropriate j
        if(H[j+1]  > H[j]) {
            j = j+1;
        }
        //if child is bigger than parent
        if(H[j] > H[i]) {
            //swapping occurs
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2*i;
        } else {
            break;
        }
    }
    //Heap Sort Part
    H[currHeapSizeIndex] = val;
    //return is not redundant
    return val;
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
    /*
        - ZEROTH INDEX - WE WILL NOT USE IT FOR BINARY HEAP IMPLEMENTATION
    */
    int n = 8;
    int A[8] = {0,10,20,30,25,5,40,35};
    //index i = 1 is already part of single element max heap
    int i = 2;
    for(int i = 2; i < n; i++) {
        Insert(A, i);
    }
    //printing heap
    print(A, 8);

    //deleting elements from Heap
    for(int j = n-1; j >= 1; j--) {
        Delete(A, j);
    }
    print(A,8);
}