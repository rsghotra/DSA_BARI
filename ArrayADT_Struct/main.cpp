/*
Array Abstract Data Type:
 - We will implement Array Class
 - Every operation and every property

*/
#include <iostream>
using namespace std;

// >========> Global Structures
struct Array {
    int A[20]; //using dynamic array
    int size;
    int length;
};

// >========> Functions Signtures

void append(Array*, int);
void display(Array*);
void insert(Array*, int, int);
int  remove(Array*, int);
void reverse(Array*);
void swap(int*, int*);
int get(Array*, int);
void set(Array*, int, int);
float avg(Array* arr);
int max(Array*);
int min(Array*);
int sum(Array*);
int sum_recursive(Array* a, int n);
int linearSearch(const Array*, int key);
int linearSearch_Transpose(Array*, int key);
int lineraSearch_MoveFront(Array*, int key);
int binarySearch_Iterative(Array*, int);
int binarySearch_Recursive(Array*, int, int, int);
Array* merge(Array, Array);
Array* Union(Array, Array);
Array* Intersection(Array, Array);
Array* Difference(Array, Array);
bool isSorted(Array);
void Rearrange(Array*);
void insert_in_sorted_array(Array*, int);
void Rearrange(Array*);


// >========> Functions

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int get(Array* a, int index) {
    if(index >= 0 && index < a->length) {
        return a->A[index];
    }
    return -1;
}

void set(Array* a, int index, int val) {
    if(index >= 0 && index < a->length) {
        a->A[index] = val;
    }
}

int max(Array* a) {
    //seeding
    int max=a->A[0];
    int i;
    for(i=1;i<a->length;i++) {
        if(max > a->A[i]) {
            max=a->A[i];
        }
    }
    return max;
}

int min(Array* a) {
    //seeding
    int min=a->A[0];
    int i;
    for(i=1;i<a->length;i++) {
        if(min < a->A[i]) {
            min=a->A[i];
        }
    }
    return min;
}

int sum_recursive(Array* a, int n) {
    if(n < 0) return 0;
    else return sum_recursive(a, n-1) + n;
}

int sum(Array* a) {
    int s=0;
    for(int i=0;i<a->length; i++) {
        s+=a->A[i];
    }
    return s;
}

float avg(Array* arr) {
    return (float)sum(arr)/arr->length;
}


int linearSearch(const Array* a, int key) {
    for(int i=0;i< a->length;i++) {
        if(a->A[i]==key) {
            return i;
        }
    }
    return -1;
}

int linearSearch_Transpose(Array* a, int key) {
    //In transpose method - when we find the key we move it to one
    //Index up so that next time it is search - algo have to to 1 less comparison
    for(int i=0;i< a->length;i++) {
        if(a->A[i]==key) {
            //Move the element 1 position up
            swap(&a->A[i-1], &a->A[i]);
            return i;
        }
    }
    return -1;
}

int linearSearch_MoveFront(Array* a, int key) {
    //In transpose method - when we find the key we move it to head
    //Index up so that next time it is search - algo have can get it O(1)
    for(int i=0;i< a->length;i++) {
        if(a->A[i]==key) {
            //Move the element 1 position up
            swap(&a->A[i], &a->A[0]);
            return i;
        }
    }
    return -1;
}

int binarySearch_Iterative(Array* a, int key) {
    int low=0, high=a->length-1;
    int mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(a->A[mid]==key) return mid;
        else if(a->A[mid] < key) {
            low=mid+1;
        } else high=mid-1;
    }
    return -1;
}

int binarySearch_Recursive(Array* a, int low, int high, int key) {
    if(low<=high) {
        int mid=(low+high)/2;
        if(key==a->A[mid]) return mid;
        else if(key<a->A[mid]) return binarySearch_Recursive(a, low, mid-1, key);
        else return binarySearch_Recursive(a, mid+1, high, key);
    }
    return -1;
}

void append(Array* ptr, int val) {
    //first we will check if there is a space available or not
    if(ptr->length==ptr->size) {
        std::cout << "Sorry - can not append as array is already full."<<std::endl;
        return;
    }
    //now everything is clear;
    ptr->A[ptr->length]=val;
    ptr->length++;
}

void insert(Array* a, int index, int val) {
    //first we will check if the array is not full
    if(index < 0) {
        std::cout<<"Sorry, Invalid Index."<<std::endl;
        return;
    }
    if(index > a->length) {
        std::cout<<"Sorry, Invalid Index Asked is out of length."<<std::endl;
        return;
    }
    if(a->length==a->size) {
        std::cout<<"Sorry, array is full. Hence, I can not insert in it."<<std::endl;
        return;
    }
    for(int i=a->length; i>index;i--) {
        //backward copy
        a->A[i]=a->A[i-1];
    }
    //A[index is now empty]
    a->A[index]=val;
    a->length++;
}

int remove(Array* a, int index) {
    //now instead of checking for edge cases first and then return them.
    //I will instead write a tight valid case;
    if(index >= 0 && index < a->length) {
        int val=a->A[index];
        for(int i=index;i< a->length-1;i++) {
            //forward copy
            a->A[i] = a->A[i+1];
        }
        a->length--;
        return val;
    }
    return -1;
}

void reverse(Array* a) {
    std::cout<<"Reversing the array now."<<std::endl;
    int i=0;
    int j=a->length-1;
    int temp;
    for(i,j;i<j;i++,j--) {
        swap(&a->A[i], &a->A[j]);
    }
}

void display(Array* a) {
    std::cout<<"Array Size: "<<a->size<<"; Array Length: "<<a->length<<std::endl;
    std::cout<<"Displaying Array."<<std::endl;
    for(int i=0;i<a->length;i++) {
        std::cout<<a->A[i]<<" ";
    }
    std::cout<<std::endl;
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
    Array stru={{2,3,4,5,6}, 10, 5}; //in stack
    display(&stru);
    append(&stru, 7);
    display(&stru);
    insert(&stru, 3, 15);
    display(&stru);
    insert(&stru, -3, 25);
    display(&stru);
    std::cout << "Removed element "<<remove(&stru, 3) << std::endl;
    display(&stru);
    std::cout << "Removed element "<<remove(&stru, 9) << std::endl;
    display(&stru);
    std::cout << "Removed element "<<remove(&stru, 0) << std::endl;
    display(&stru);

    std::cout<<">======>Linear Search:"<<std::endl;
    std::cout<<"Element  found at: " << linearSearch(&stru, 14/2) << std::endl;

    std::cout<<">======>Linear Search Transpose:"<<std::endl;
    std::cout<<"Element  found at: " << linearSearch(&stru, 14/2) << std::endl;

    std::cout<<">======>Linear Search Move Front:"<<std::endl;
    std::cout<<"Element  found at: " << linearSearch(&stru, 14/2) << std::endl;

    std::cout<<">======>Binary Search Iterative"<<std::endl;
    std::cout<<"Element  found at: " << binarySearch_Iterative(&stru, 14/2) << std::endl;

    std::cout<<">======>get(index):"<<std::endl;
    std::cout<<"get(index):: " << get(&stru, 3) << std::endl;

    std::cout<<">======>set(index, val):"<< std::endl;
    std::cout<<"set(index, val):: ";
    set(&stru, 0, 19);
    std::cout<<std::endl;

    std::cout<<">======>max():"<<std::endl;
    std::cout<<"max():: " << max(&stru) << std::endl;

    std::cout<<">======>min():"<<std::endl;
    std::cout<<"min():: " << min(&stru) << std::endl;

    std::cout<<">======>sum():"<<std::endl;
    std::cout<<"sum():: " << sum(&stru) << std::endl;

    std::cout<<">======>avg():"<<std::endl;
    std::cout<<"avg():: " << avg(&stru) << std::endl;
    std::cout<<">======>reversing and displaying array:"<<std::endl;
    std::cout<<"reverse():: " <<  std::endl;
    display(&stru);
    reverse(&stru); 
    display(&stru);
    return 0;
}