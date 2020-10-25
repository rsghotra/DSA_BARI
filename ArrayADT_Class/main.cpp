/*
Array Abstract Data Type:
 - We will implement Array Class
 - Every operation and every property

*/
#include <iostream>
using namespace std;

// >========> Global Structures
class Array {
    private:
        int* A; //using dynamic array
        int size;
        int length;
        void swap(int*, int*);
    public:
        Array() {
            size=10;
            length=0;
            A=new int[size];
        }
        Array(int sz) {
            size=sz;
            length=0;
            A=new int[size];
        }
        ~Array() {
            delete [] A;
        }

        //Array Operations
        void display();
        void append(int);
        void insert(int, int);
        int  remove(int);
        void reverse();
        bool isSorted();
        void Rearrange();
        void insert_in_sorted_array(int);

        //searching
        int linearSearch(int key);
        int linearSearch_Transpose(int key);
        int linearSearch_MoveFront(int key);
        int binarySearch_Iterative(int);
        int binarySearch_Recursive(int, int, int);

        //getter+setter
        int get(int);
        void set(int, int);

        //math operations
        int max();
        int min();
        int sum();
        float avg();
        int sum_recursive(int n);

        //Merge
        Array* merge(Array);

        //Set Operations
        Array* Union(Array);
        Array* Intersection(Array);
        Array* Difference(Array);

        //Find a Single Missing Element in a sorted array.
};

// >========> Functions

void Array::swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::get(int index) {
    if(index >= 0 && index < length) {
        return A[index];
    }
    return -1;
}

void Array::set(int index, int val) {
    if(index >= 0 && index < length) {
        A[index] = val;
    }
}

int Array::max() {
    //seeding
    int max=A[0];
    int i;
    for(i=1;i<length;i++) {
        if(max > A[i]) {
            max=A[i];
        }
    }
    return max;
}

int Array::min() {
    //seeding
    int min=A[0];
    int i;
    for(i=1;i<length;i++) {
        if(min < A[i]) {
            min=A[i];
        }
    }
    return min;
}

int Array::sum_recursive(int n) {
    if(n < 0) return 0;
    else return sum_recursive(n-1) + A[n];
}

int Array::sum() {
    int s=0;
    for(int i=0;i<length; i++) {
        s+=A[i];
    }
    return s;
}

float Array::avg() {
    return (float)sum()/length;
}


int Array::linearSearch(int key) {
    for(int i=0;i< length;i++) {
        if(A[i]==key) {
            return i;
        }
    }
    return -1;
}

int Array::linearSearch_Transpose(int key) {
    //In transpose method - when we find the key we move it to one
    //Index up so that next time it is search - algo have to to 1 less comparison
    for(int i=0;i< length;i++) {
        if(A[i]==key) {
            //Move the element 1 position up
            swap(&A[i-1], &A[i]);
            return i;
        }
    }
    return -1;
}

int Array::linearSearch_MoveFront(int key) {
    //In transpose method - when we find the key we move it to head
    //Index up so that next time it is search - algo have can get it O(1)
    for(int i=0;i< length;i++) {
        if(A[i]==key) {
            //Move the element 1 position up
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int Array::binarySearch_Iterative(int key) {
    int low=0, high=length-1;
    int mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(A[mid]==key) return mid;
        else if(A[mid] < key) {
            low=mid+1;
        } else high=mid-1;
    }
    return -1;
}

int Array::binarySearch_Recursive(int low, int high, int key) {
    if(low<=high) {
        int mid=(low+high)/2;
        if(key==A[mid]) return mid;
        else if(key<A[mid]) return binarySearch_Recursive(low, mid-1, key);
        else return binarySearch_Recursive(mid+1, high, key);
    }
    return -1;
}

void Array::append(int val) {
    //first we will check if there is a space available or not
    if(length==size) {
        std::cout << "Sorry - can not append as array is already full."<<std::endl;
        return;
    }
    //now everything is clear;
    A[length]=val;
    length++;
}

void Array::insert(int index, int val) {
    //first we will check if the array is not full
    if(index < 0) {
        std::cout<<"Sorry, Invalid Index."<<std::endl;
        return;
    }
    if(index > length) {
        std::cout<<"Sorry, Invalid Index Asked is out of length."<<std::endl;
        return;
    }
    if(length==size) {
        std::cout<<"Sorry, array is full. Hence, I can not insert in it."<<std::endl;
        return;
    }
    for(int i=length; i>index;i--) {
        //backward copy
        A[i]=A[i-1];
    }
    //A[index is now empty]
    A[index]=val;
    length++;
}

int Array::remove(int index) {
    //now instead of checking for edge cases first and then return them.
    //I will instead write a tight valid case;
    if(index >= 0 && index < length) {
        int val=A[index];
        for(int i=index;i< length-1;i++) {
            //forward copy
            A[i] = A[i+1];
        }
        length--;
        return val;
    }
    return -1;
}

void Array::reverse() {
    std::cout<<"Reversing the array now."<<std::endl;
    int i=0;
    int j=length-1;
    int temp;
    for(i,j;i<j;i++,j--) {
        swap(&A[i], &A[j]);
    }
}

void Array::display() {
    std::cout<<"Array Size: "<<size<<"; Array Length: "<<length<<std::endl;
    std::cout<<"Displaying Array."<<std::endl;
    for(int i=0;i<length;i++) {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}

Array* Array:: merge(Array arr2) {
    // ||==> Watchout; Three indexes will be used. An array will be created
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<length && j<arr2.length) {
        if(A[i] < arr2.A[j]) {
            arr3->A[k] =  A[i];
            k++;
            i++;
        } else {
            arr3->A[k] =  arr2.A[j];
            k++;
            j++;
        }
    }
    //at this time one of the list must be exhausted
    while(i < length) {
        arr3->A[k] =  A[i];
        k++;
        i++;
    }
    while(j < arr2.length) {
        arr3->A[k] =  arr2.A[j];
        k++;
        j++;
    }
    //Remember we had not yet set the size or length of array3
    arr3->length=length+arr2.length;
    arr3->size=10;
    return arr3;
}

Array* Array::Union(Array arr2) {
    //Union of two sets means the resulting sets will have all the unique elements from both A and B.
    // ||==> Watchout; Three indexes will be used. An array will be created
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<length && j<arr2.length) {
        if(A[i] < arr2.A[j]) {
            arr3->A[k] =  A[i];
            k++;
            i++;
        } else if(A[i] > arr2.A[j]) {
            arr3->A[k] =  arr2.A[j];
            k++;
            j++;
        } else {
            arr3->A[k] =  A[i];
            k++;
            i++;
            j++;
        }
    }
    //at this time one of the list must be exhausted
    while(i < length) {
        arr3->A[k] =  A[i];
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

Array* Array::Intersection(Array arr2) {
    // Intersection of Two Sets Means: Only common elements of Set A and Set B
    // ||==> Watchout; Three indexes will be used. An array will be created
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<length && j<arr2.length) {
        if(A[i] < arr2.A[j]) {
            // ||==> Watchout; K is not increasing
            i++;
        } else if(A[i] > arr2.A[j]){
            j++;
        } else {
            //when equal means this the element we are going to push
            arr3->A[k] =  A[i];
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

Array* Array::Difference(Array arr2) {
    // ||==> Watchout; Three indexes will be used. An array will be created
    // Difference of SetA-SetB = Those elements which are in set A but not in B.
    Array* arr3 = new Array;
    int i = 0, j = 0, k = 0;
    //Loop will stop when one of the list is exhausted.
    while(i<length && j<arr2.length) {
        if(A[i] < arr2.A[j]) {
            arr3->A[k] =  A[i];
            k++;
            i++;
            // we do not want to copy any thing from Set B
        } else if(A[i] > arr2.A[j]){
            j++;
        } else {
            i++;
            j++;
        }
    }
    //at this time one of the list must be exhausted
    while(i < length) {
        arr3->A[k] =  A[i];
        k++;
        i++;
    }
    //Not required to merge remaining elements of Set B
    //Remember we had not yet set the size or length of array3
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

bool Array::isSorted() {
    // ||==> Watchout; We are traversing until second last element due to forward copy operations.
    // ||==> Watchout: We start from the beginning
    for(int i=0;i<length-1;i++)  {
        if(A[i]>A[i+1]) return false;
    }
    return true;
}

void Array::insert_in_sorted_array(int val) {
    //weeding out invalid and only going in if length < size
    if(length < size) {
        // ||==> Watchout; TRAVERSING FROM BACK TO FRONT UNTIL VAL < A[i]
        // ||==> Watchout: We start from the END. ACTUALLY AT LENGTH
        int i = length-1;
        while(i>=0 && A[i] > val) {
            //perform forward copy; reduce value of i
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=val;
        length++;
    }
}

/*
Function which rearranges the array in such a way that all the negative 
*/
void Array::Rearrange() {
    // ||==> Watchout; Two indexes will be used 
    //i is hunting for positive number and will increase until it see a negative number
    //j is hunting for negative number
    //we must stop unil i is less than j
    //i starts from 0
    //j starts from the end of the array
    int i=0;
    int j=length-1;
    while(i<j) {
        while(A[i] < 0) i++;
        //||==> Watchout; j--
        while(A[j] >= 0) j--;
        if(i<j) {
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
}



int main()
{
    Array *arr1;
    int ch,sz;
    int x,index;

    cout<<"Enter Size of Array";
    cin>>sz;
    arr1=new Array(sz);
    do
    {
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Sum\n";
        cout<<"5. Display\n";
        cout<<"6.Exit\n";

        cout<<"enter you choice ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
                cout<<"Enter an element and index ";
                cin>>x>>index;
                arr1->insert(index,x);
                break;
            case 2:
                cout<<"Enter index ";
                cin>>index;
                x=arr1->remove(index);
                cout<<"Deleted Element is"<<x;
                break;
            case 3:
                cout<<"Enter element to search";
                cin>>x;
                index=arr1->linearSearch(x);
                cout<<"Element index "<<index;
                break;
            case 4:
                cout<<"Sum is "<<arr1->sum();
                break;
            case 5:
                arr1->display();
        }
    } while(ch<6);
    return 0;
}