#include <iostream>
#include <string>

using namespace std;
/*
Checking if given array is already sorted
*/

struct Array {
    int A[10];
    int length;
    int size;
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

void insert_in_sorted_array(Array* arr, int val) {
    //weeding out invalid and only going in if length < size
    if(arr->length < arr->size) {
        // ||==> Watchout; TRAVERSING FROM BACK TO FRONT UNTIL VAL < A[i]
        // ||==> Watchout: We start from the END. ACTUALLY AT LENGTH
        int i = arr->length-1;
        while(i>=0 && arr->A[i] > val) {
            //perform forward copy; reduce value of i
            arr->A[i+1]=arr->A[i];
            i--;
        }
        arr->A[i+1]=val;
        arr->length++;
    }
}

/*
Function which rearranges the array in such a way that all the negative 
*/
void Rearrange(Array* arr) {
    // ||==> Watchout; Two indexes will be used 
    //i is hunting for positive number and will increase until it see a negative number
    //j is hunting for negative number
    //we must stop unil i is less than j
    //i starts from 0
    //j starts from the end of the array
    int i=0;
    int j=arr->length-1;
    while(i<j) {
        while(arr->A[i] < 0) i++;
        //||==> Watchout; j--
        while(arr->A[j] >= 0) j--;
        if(i<j) {
            int temp = arr->A[j];
            arr->A[j] = arr->A[i];
            arr->A[i] = temp;
        }
    }
}

Array* merge(Array arr1, Array arr2) {
    // ||==> Watchout; Three indexes will be used. An array will be created
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<arr1.length && j<arr2.length) {
        if(arr1.A[i] < arr2.A[j]) {
            arr3->A[k] =  arr1.A[i];
            k++;
            i++;
        } else {
            arr3->A[k] =  arr2.A[j];
            k++;
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
    arr3->length=arr1.length+arr2.length;
    arr3->size=10;
    return arr3;
}

int main() {
    //initialized
    Array arr = {{-6, 3, -3, 10, 5, -7, -9, 12, -4}, 9, 10};
    cout<<">==>Displaying array: "<<endl;
    Display(&arr);
    if(isSorted(arr)) {
        cout << ">==>isSorted():The array is Sorted."<<endl;
        cout << ">==>insert_in_sorted_array(): Inserting in a sorted array. ";
        insert_in_sorted_array(&arr, 10);
        Display(&arr);
        insert_in_sorted_array(&arr, 1);
        Display(&arr);
    } else {
        cout << ">==>isSorted():Array Not Sorted!"<<endl;
    }
    Rearrange(&arr);
    Display(&arr);

    cout << ">==>Merging two sorted arrays.";
    Array arr1 = {{1,3,5,7,9}, 5, 10};
    Array arr2 = {{2,4,6,8,10}, 5, 10};
    Array* arr3 = merge(arr1, arr2);
    Display(arr3);
    return 0;   
}