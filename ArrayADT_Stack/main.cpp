/*
Array Abstract Data Type:
 - We will implement Array Class
 - Every operation and every property

*/
#include <iostream>

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

// >========> Functions

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

void display(Array* a) {
    std::cout<<"Array Size: "<<a->size<<"; Array Length: "<<a->length<<std::endl;
    std::cout<<"Displaying Array."<<std::endl;
    for(int i=0;i<a->length;i++) {
        std::cout<<a->A[i]<<" ";
    }
    std::cout<<std::endl;
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
    return 0;
}