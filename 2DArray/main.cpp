#include <iostream>

/*
Program demonstrated how we can declare 2D array in C++
1. Declaring in Stack: int A[3][4];
2. Partial Declaration in Stack and partial in Heap: Using single pointer
3. Fully Dynamic 2D array: Using double pointer
*/
int main() {
    //1. Full 2D array in Stack
    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {3,6,9,12}};
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    //2. Partial Array in Stack and partial in heap;
    //Created array of pointer to int in a stack; See no use of new operator
    int* Array[3];
    Array[0]=new int[4];
    Array[1]=new int[4];
    Array[1]=new int[4];
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            std::cout << Array[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    //3. Fully Dynamic 2D Array - Using double ptr
    int **dPtr;
    dPtr= new int*[3];
    dPtr[0]=new int[4];
    dPtr[1]=new int[4];
    dPtr[2]=new int[4];
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            std::cout << dPtr[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}