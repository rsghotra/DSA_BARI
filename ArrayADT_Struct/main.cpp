/*
Array Abstract Data Type:
 - We will implement Array Class
 - Every operation and every property
 - HASH DECLRATION GUIDELINES: SET SIZE TO MAX ELEMENT IN THE ARRAY.
 - FOLLOWING THINGS ARE KNOWN TO THE QUESTION:
            - Min Element in the array.
            - Max Element in the array.
            - Caveat: Must create Hash of Size: MAX+1
            - MUST INITIALIZE THE HASH TO ZERO: //https://stackoverflow.com/questions/2204176/how-to-initialise-memory-with-new-operator-in-c 
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
void display(const Array*);
void insert(Array*, int, int);
int  remove(Array*, int);
void reverse(Array*);
void swap(int*, int*);
int get(Array*, int);
void set(Array*, int, int);
float avg(Array* arr);
int max(const Array*);
int min(const Array*);
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
void FindSingleMissingFormula(const Array*);
void FindSingleMissingIndex(const Array*);


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

int max(const Array* a) {
    //seeding
    int max=a->A[0];
    int i;
    for(i=1;i<a->length;i++) {
        if(max < a->A[i]) {
            max=a->A[i];
        }
    }
    return max;
}

int min(const Array* a) {
    //seeding
    int min=a->A[0];
    int i;
    for(i=1;i<a->length;i++) {
        if(min > a->A[i]) {
            min=a->A[i];
        }
    }
    return min;
}

int sum_recursive(Array* a, int n) {
    if(n < 0) return 0;
    else return sum_recursive(a, n-1) + n;
}

int sum_n(int n) {
    if(n < 0) return 0;
    else return sum_n(n-1) + n;
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

void display(const Array* a) {
    std::cout<<"Array Size: "<<a->size<<"; Array Length: "<<a->length<<std::endl;
    std::cout<<"Displaying Array."<<std::endl;
    cout << "| ";
    for(int i=0;i<a->length;i++) {
        std::cout<<a->A[i]<<" | ";
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

/*
*************FINDS SINGLE MISSING ELEMENT IN SORTED ARRAY**********
*/

void FindSingleMissingFormula(const Array* arr) {
    int low=arr->A[0];
    int high=arr->A[arr->length-1];
    int i=0,foundSum=0,shouldBeSum=0,subSum=0;
    for(i;i<arr->length;i++) {
        foundSum+=arr->A[i];
    }
    shouldBeSum = (high*(high+1))/2;
    //means sequence of first n natural numbers;
    //standard formula
    if(low!=0) {
        subSum=sum_n(low-1);
        shouldBeSum=shouldBeSum-subSum;
    }
    cout << "Missing element is: " << (shouldBeSum - foundSum) << endl;
}

void FindSingleMissingIndex(const Array* arr) {
    int i=0;
    int diff = arr->A[i] - i;
    for(i;i<arr->length;i++) {
        if(arr->A[i] - i !=diff) {
            cout << "Missing Element: " << diff+i << endl;
            break;
        }
    }
}

void _FindSingleMissingInSorted() {
    Array stru={{1,2,3,4,6,7,8,9,10}, 10, 9}; //in stack
    cout <<"Find Missing Element IN A SORTED LIST problem has TWO soultions: BY FORMULA OR ITERATIVE. BOTH HAS INDEX MATH INVOLVED."<<endl;
    cout << "Input Array: ";
    display(&stru);
    int choice=0;
    do {
        cout << "1. Formula Solution: O(n);" << endl;
        cout << "2. Index Manipulation Solution: O(n);" << endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
    } while(choice != -1 && choice != 1 && choice !=2);
    switch(choice) {
        case 1:
            FindSingleMissingFormula(&stru);
            break;
        case 2:
            FindSingleMissingIndex(&stru);
            break;
        default:
            break;
    }
}

/*
*************FINDS MULTIPLE MISSING ELEMENTS IN SORTED ARRAY**********
*/

void FindMissingElemsInSorted(const Array* arr) {
    cout << "Missing Elements: ";
    int i=0, diff=arr->A[i]-i;
    for(i;i<arr->length;i++) {
        if(arr->A[i]-i != diff) {
            //if list is sorted than difference will be greater than zero
            while(diff < arr->A[i]-i) {
                cout << diff + i << " ";
                diff++;
            }
        }
    }
    cout << endl;
}

void _FindMissingElemsInSorted() {
    Array stru={{6,7,8,9,11,12,15,16,17,18,19}, 11, 11}; //in stack
    cout <<"FINDING ALL MISSING ELEMENTS IN A SORTED ARRAY HAS ONE EASY SOLUTION: SEE AS \"INDEX VS VALUE PROBLEM.\""<<endl;
    cout << "Input Array: ";
    display(&stru);
    FindMissingElemsInSorted(&stru);
}

/*
*************FINDS MULTIPLE MISSING ELEMENTS IN AN UNSORTED ARRAY**********
*/

void FindMissingElemsInUnSorted(const Array* arr) {
    cout << "Missing Elements: ";
    int i=0;
    display(arr);
    int mx=max(arr);
    int* H=new int[mx+1];
    //initializing the HASH to zero
    //we will not used 0th index as our logic is build on zero index.
    //Initializing the HASH array with 1.
    for(i;i<=mx;i++) {
        H[i] = 0;
    }
    i=0;
    for(i;i<arr->length;i++) {
        H[arr->A[i]]++;
    }
    i=1;
    for(i;i<=mx;i++) {
        if(H[i]==0) {
            cout << i << " ";
        }
    }
    cout << endl;
    delete [] H;
    H=0;
}
void _FindMissingElemsInUnSorted() {
    Array stru={{3,7,4,9,12,6,1,11,2,10}, 10, 10}; //in stack
    cout <<"FINDING ALL MISSING ELEMENTS IN AN UNSORTED ARRAY: USE HASH ALWAYS. SEQUENCE MUST NOT CONTAINS ZERO, HANDLES DUPLICATES.\""<<endl;
    cout << "Input Array: ";
    display(&stru);
    FindMissingElemsInUnSorted(&stru);
}
/*
*************FINDS DUPLICATES IN A SORTED ARRAY**********
*/

void DuplicateFinderSorted(const Array* arr) {
    cout << "Duplicate Elements: ";
    //must also ensure to handle continuous duplicates and not re-printing them;
    int i=0, lastDuplicate=0;
    for(i;i<arr->length-1;i++) {
        if(arr->A[i] == arr->A[i+1] && lastDuplicate!=arr->A[i]) {
            cout << arr->A[i] << " ";
            lastDuplicate=arr->A[i];
        }
    }
    cout << endl;
}

void _DuplicateFinderSorted() {
    Array stru={{3,6,8,8,10,12,15,15,15,20}, 10, 10}; //in stack
    cout <<"FINDING DUPLICATES FROM A SORTED ARRAY HAS SINGLE ITERATIVE SOLUTION.\""<<endl;
    cout << "Input Array: ";
    display(&stru);
    DuplicateFinderSorted(&stru);
}

/*
*************FINDS & COUNT DUPLICATES IN A SORTED ARRAY**********
*/

void DuplicateHunterSorted_Iterative(const Array* arr) {
    int i=0,j=0;
    for(i;i<arr->length-1;i++) {
        if(arr->A[i]==arr->A[i+1]) {
            j=i+1;
            while(arr->A[j]==arr->A[i]) {
                j++;
            }
            //now it is time to print the element and number of repetitions.
            cout << "Element " << arr->A[i] << " is repeating " << j-i << " times." << endl;
            //at this time - we ARE going MAKE i jump to one location before the j. Which will be last duplicated entry of current elements.
            i=j-1;
        }
    }
}

void DuplicateHunterSorted_Hash(const Array* arr) {
    /*
        >--> As it is a hash question on an Array. Alaways remember that we have these things known:
            - Min Element in the array.
            - Max Element in the array.
            - Caveat: Must create Hash of Size: MAX+1 & INITIALIZE THEM TO ZERO
    */
    int i;
    int minElem=min(arr);
    int maxElem=max(arr);
    int* H = new int[maxElem+1]();
    i=0;
    for(i;i<arr->length;i++) {
        H[arr->A[i]]++;
    }
    //Iterating over hash and printing.
    //setting the starting hash to min element.
    i=minElem;
    for(i;i<maxElem+1;i++) {
        if(H[i] > 1) {
            cout << "Element " << i << " is repeating " << H[i] << " times." << endl;
        }
    }
    delete[] H;
    H=0;
}

void _DuplicateHunterSorted() {
    Array stru={{3,6,8,8,10,12,15,15,15,20}, 10, 10}; //in stack
    cout <<"Find & Counting Missing Element IN A SORTED LIST problem has TWO soultions: ITERATIVE(O(N)) & HASHING (O(N)))."<<endl;
    cout << "Input Array: ";
    display(&stru);
    int choice=0;
    do {
        cout << "1. Iterative Solution: Since the list is SORTED. Therefore, the solution is O(n)." << endl;
        cout << "2. Hash Solution: Obviously O(n) with O(n) S(n) BUT IS FAST;" << endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
    } while(choice != -1 && choice != 1 && choice !=2);
    switch(choice) {
        case 1:
            DuplicateHunterSorted_Iterative(&stru);
            break;
        case 2:
            DuplicateHunterSorted_Hash(&stru);
            break;
        default:
            break;
    }
}

/*
*************FINDS & COUNT DUPLICATES IN AN UNSORTED ARRAY**********
*/

void DuplicateHunterUnSorted_Iterative(Array* arr) {
    int i=0;
    //Copying the array as we will modify the array to mark it.
    Array temp;
    temp.length=arr->length;
    temp.size=arr->size;
    for(i;i<arr->length-1;i++) {
        temp.A[i] = arr->A[i];
    }
    i=0;
    int j, occurence;
    for(i;i<temp.length-1;i++) {
        j=i+1;
        occurence=1;
        for(j;j<temp.length;j++) {
            //element -1 means that it is marked that element is seen
            if(temp.A[i]==temp.A[j] && temp.A[j] != -1) {
                occurence++;
                temp.A[j] = -1;
            }
        }
        if(occurence>1) {
            cout << "Element " << temp.A[i] << " is repeating " << occurence << " times." << endl;
        }
    }
}

void DuplicateHunterUnSorted_Hash(const Array* arr) {
    int i=0;
    int minElem=min(arr);
    int maxElem=max(arr);
    int* H = new int[maxElem+1]();
    for(i;i<arr->length;i++) {
        H[arr->A[i]]++;
    }
    i=minElem;
    for(i;i<maxElem+1;i++) {
        if(H[i] > 1) {
            cout << "Element " << i << " is repeating " << H[i] << " times." << endl;
        }
    }
    delete [] H;
    H=0;
}

void _DuplicateHunterUnSorted() {
    Array stru={{8,3,6,4,6,5,6,8,7,2}, 10, 10}; //in stack
    cout <<"Find Missing Element IN AN UNSORTED LIST HAS TWO SOLUTIONS: ITERATIVE- O(N2) - Obviously; Only god can find duplicates; HASH - O(N);O(N)"<<endl;
    cout << "Input Array: ";
    display(&stru);
    int choice=0;
    while(choice != -1) {
        do {
        cout << "1. Iterative Solution: O(N2). Setting seen duplicate elements to -1 startegy." << endl;
        cout << "2. Hashing Solution: T(n)=O(n); S(n)=O(n);" << endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
        } while(choice != -1 && choice != 1 && choice !=2);
        switch(choice) {
            case 1:
                DuplicateHunterUnSorted_Iterative(&stru);
                break;
            case 2:
                DuplicateHunterUnSorted_Hash(&stru);
                break;
            default:
                break;
        }
    }
}

/*
*************FINDS PAIR OF ELEMENTS WITH SUM K IN AN UNSORTED ARRAY**********
*/
void FindPairSumUnsorted_Iterative(Array* arr, int k) {
    int i=0,j;
    for(i;i<arr->length-1;i++) {
        j=i+1;
        for(j;j<arr->length;j++) {
            if(arr->A[i]+arr->A[j]==k) {
                cout << arr->A[i] << "+" << arr->A[j]<<"="<<k<<endl;
            }
        }
    }
    cout << endl;
}

void FindPairSumUnsorted_Hash(const Array* arr, int k) {
    int miElem=min(arr);
    int maElem=max(arr);
    int* H = new int[maElem+1]();
    int i = 0;
    for(i;i<arr->length;i++) {
        H[arr->A[i]]++;
    }
    i=miElem;
    for(i;i<maElem;i++) {
        if(H[i]!=0 && H[k-i]!=0) {
            cout << "Pair Found: ";
            cout << i << "+" << (k-i) <<"="<<k<<endl;
        }
    }
}

void _FindPairSumUnsorted() {
    Array stru={{6,3,8,10,16,7,5,2,9,14}, 10, 10}; //in stack
    cout <<"Finding PAIR SUM IN AN UNSORTED LIST HAS TWO SOLUTIONS: ITERATIVE- O(N2) & HASH - O(N);O(N)"<<endl;
    cout << "Input Array: ";
    display(&stru);
    int choice=0;
    while(choice != -1) {
        do {
        cout << "1. Iterative Solution: O(N2)." << endl;
        cout << "2. Hashing Solution: T(n)=O(n); S(n)=O(n);" << endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
        } while(choice != -1 && choice != 1 && choice !=2);
        switch(choice) {
            case 1:
                FindPairSumUnsorted_Iterative(&stru, 10);
                break;
            case 2:
                FindPairSumUnsorted_Hash(&stru, 10);
                break;
            default:
                break;
        }
    }
}

/*
*************FINDS PAIR OF ELEMENTS WITH SUM K IN A SORTED ARRAY**********
*/

void FindPairSumSorted_iterative(Array* arr, int k) {
    //As we will not be increasing or decreaing counter in every iteration
    //Hence, we will use while loop
    int i=0, j=arr->length-1;
    while(i<j) {
        if(arr->A[i]+arr->A[j]==k) {
            cout << arr->A[i] << "+" << arr->A[j]<<"="<<k<<endl;
            i++;
            j--;
        } else if(arr->A[i]+arr->A[j] < k) {
            i++;
        } else {
            j--;
        }
    }
    cout << endl;
 }

void _FindPairSumSorted() {
    Array stru={{1,3,4,5,6,8,9,10,12,14}, 10, 10}; //in stack
    cout <<"PAIR SUM IN A SORTED ARRAY HAS ONE SOLUTION ONLY: ITERATIVE- O(N). Very Sophisticated."<<endl;
    FindPairSumSorted_iterative(&stru, 10);
}

/*
*************FINDS MIN-MAX OF UNSORTED ARRAY IN ONE GO**********
*/

void FindMinMaxUnsorted(Array* arr) {
    int i=1;
    //SEED MUST BE FIRST ELEMENT OF THE ARRAY
    int miVal=arr->A[0];
    int maVal=arr->A[0];
    for(i;i<arr->length;i++) {
        if(arr->A[i] < miVal) {
           miVal=arr->A[i]; 
        } else if(arr->A[i] > maVal) {
            maVal=arr->A[i];
        }
    }
    cout << "*Min Val Element: " << miVal << endl;
    cout << "*Max Val Element: " << maVal << endl;
 }

void _FindMinMaxUnsorted() {
    Array stru={{8,3,6,4,6,5,6,8,7,2}, 10, 10}; //in stack
    cout <<"Find MIN-MAX IN AN UNSORTED ARRAY HAS ONE SOLUTION ONLY: ITERATIVE- O(N) & 2(n-1) worst case comparison."<<endl;
    cout << "Input Array: ";
    display(&stru);
    FindMinMaxUnsorted(&stru);
}

int main() {
    int choice=0;
        do {
            cout<<"\n\n==============Wonderwold of Array============" << endl;
            cout<<"Welcome! What would you like to do today?" << endl;
            cout << "1. Find Single Missing Element in A SORTED array." << endl;
            cout << "2. Find All Missing Elements in A SORTED array." << endl;
            cout << "3. Find All Missing Elements in AN UNSORTED array."<<endl;
            cout << "4. Find Duplicates in a SORTED array."<<endl;
            cout << "5. Find & Count Duplicates in a SORTED array."<<endl;
            cout << "6. Find & Count Duplicates in AN UNSORTED array."<<endl;
            cout << "7. Find Pair Sum in a SORTED array."<<endl;
            cout << "8. Find Pair Sum in AN UNSORTED array."<<endl;
            cout << "9. Find MAX and MIN in A SINGLE SCAN."<<endl;
            cout << "-1. To Exit." << endl;
            cin >> choice;
        } while(choice != -1 && !(choice >= 1 && choice <=9));

        switch(choice) {
            case 1:
                _FindSingleMissingInSorted();
                break;
            case 2:
                _FindMissingElemsInSorted();
                break;
            case 3:
                _FindMissingElemsInUnSorted();
                break;
            case 4:
                _DuplicateFinderSorted();
                break;
            case 5:
                _DuplicateHunterSorted();
                break;
            case 6:
                _DuplicateHunterUnSorted();
                break;
            case 7:
                _FindPairSumSorted();
                break;
            case 8:
                _FindPairSumUnsorted();
                break;
            case 9:
                _FindMinMaxUnsorted();
                break;
            case -1:
                cout << "Thank You for Visiting the World of Arrays! :)" << endl; 
        }
    return 0;
}