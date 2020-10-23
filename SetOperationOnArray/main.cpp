#include <iostream>
#include <string>

using namespace std;
/*
Checking if given array is already sorted
*/

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(const Array *a) {
    //as it is passed by value therefore - hence it is an object
    for(int i=0;i<a->length;i++) {
        cout<< a->A[i] << " ";
    }
    cout<<endl;
}

bool isSorted(Array a) {
    // ||==> Watchout; We are traversing until second last element due to forward copy operations.
    // ||==> Watchout: We start from the beginning
    for(int i=0;i<a.length-1;i++)  {
        if(a.A[i]>a.A[i+1]) return false;
    }
    return true;
}


Array* Union(Array arr1, Array arr2) {
    //Union of two sets means the resulting sets will have all the unique elements from both A and B.
    // ||==> Watchout; Three indexes will be used. An array will be created
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<arr1.length && j<arr2.length) {
        if(arr1.A[i] < arr2.A[j]) {
            arr3->A[k] =  arr1.A[i];
            k++;
            i++;
        } else if(arr1.A[i] > arr2.A[j]) {
            arr3->A[k] =  arr2.A[j];
            k++;
            j++;
        } else {
            arr3->A[k] =  arr1.A[i];
            k++;
            i++;
            j++;
        }
    }
    //at this time one of the list must be exhausted
    while(i < arr1.length) {
        arr3->A[k] =  arr1.A[i];
        k++;
        i++;
    }
    while(j < arr2.length) {
        arr3->A[k] =  arr2.A[j];
        k++;
        j++;
    }
    //Remember we had not yet set the size or length of array3
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

Array* Intersection(Array arr1, Array arr2) {
    // Intersection of Two Sets Means: Only common elements of Set A and Set B
    // ||==> Watchout; Three indexes will be used. An array will be created
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<arr1.length && j<arr2.length) {
        if(arr1.A[i] < arr2.A[j]) {
            // ||==> Watchout; K is not increasing
            i++;
        } else if(arr1.A[i] > arr2.A[j]){
            j++;
        } else {
            //when equal means this the element we are going to push
            arr3->A[k] =  arr1.A[i];
            i++;
            j++;
            k++;
        }
    }
    //jadon list hi muk gayi te fer baaki elements da achaar pauna

    //Remember we had not yet set the size or length of array3
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

Array* Difference(Array arr1, Array arr2) {
    // ||==> Watchout; Three indexes will be used. An array will be created
    // Difference of SetA-SetB = Those elements which are in set A but not in B.
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<arr1.length && j<arr2.length) {
        if(arr1.A[i] < arr2.A[j]) {
            arr3->A[k] =  arr1.A[i];
            k++;
            i++;
            // we do not want to copy any thing from Set B
        } else if(arr1.A[i] > arr2.A[j]){
            j++;
        } else {
            i++;
            j++;
        }
    }
    //at this time one of the list must be exhausted
    while(i < arr1.length) {
        arr3->A[k] =  arr1.A[i];
        k++;
        i++;
    }
    //Not required to merge remaining elements of Set B
    //Remember we had not yet set the size or length of array3
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

int main() {

    Array arr1 = {{2,9,21,28,35}, 10, 5};
    Array arr2 = {{2,4,6,8,10}, 10, 5};
    cout << ">==>Set operations on two sets implemented as Arrays.";
    cout << ">==>Set1: " << " ";
    Display(&arr1);
    cout << ">==>Set2: " << " ";
    Display(&arr2);
    cout << "Set1 Union Set2: ";
    Array* arr3 = Union(arr1, arr2);
    Display(arr3);
    delete [] arr3;
    cout << "Set1 Intersection Set2: ";
    arr3 = Intersection(arr1, arr2);
    Display(arr3);
    delete [] arr3;
    cout << "Set1 Difference Set2: ";
    arr3 = Difference(arr1, arr2);
    Display(arr3);
    delete [] arr3;
    return 0;   
}