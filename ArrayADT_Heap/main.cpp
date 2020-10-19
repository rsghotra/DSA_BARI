/*
Array Abstract Data Type:
 - We will implement Array Class
 - Every operation and every property

*/
#include <iostream>

struct Array {
    int *A; //using dynamic array
    int size;
    int length;
};

void display(Array a) {
    std::cout<<"Displaying Array."<<std::endl;
    for(int i=0;i<a.length;i++) {
        std::cout<<a.A[i]<<std::endl;
    }
}

int main() {
    Array arr; //in stack
    do {
        std::cout<<"Enter the size of the array(1-999)." << std::endl;
        std::cin >> arr.size;
    } while(arr.size<0||arr.size>999);
    //creating array in heap now.
    arr.A=new int[arr.size];
    //filling the array
    do {
        std::cout<<"How many elements in the array you are going to enter?"<<std::endl;
        std::cin>>arr.length;
    } while(arr.length < 0 || arr.length > arr.size );
    

    for(int i=0;i<arr.length;i++) {
        std::cout<<"Enter the "<<i<<" element: "<<std::endl;
        std::cin>>arr.A[i];
    }
    display(arr);
    return 0;
}