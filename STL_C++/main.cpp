#include<iostream>
#include<iomanip>
#include<array>
using namespace std;

const size_t rows{2};
const size_t cols{3};
void printArray(const array<array<int, cols>, rows>&);
int sum(const array<array<int, cols>, rows>& a);

int main() {
    array<array<int, cols>, rows> array1{1,2,3,4,5,6};
    array<array<int, cols>, rows> array2{1,2,3,4};

    cout << "Values in the array by row1 are: " << endl;
    printArray(array1);

    cout << "Values in the array2 by row are: " << endl;
    printArray(array2);
    cout << "Sum of all elements if the 2D array " << sum(array1) << endl;
    return 0;
}

void printArray(const array<array<int, cols>, rows>& a) {
    //for printing a 2'D array -you must use auto keyword
    /*
        Three things happening here:
            - const
            - auto
            - reference
    */
   //why you are looking for index. It is a range based for loop
    for(const auto& row: a) {
        for(const auto& element: row) {
            cout << element << ' ';
        }
        cout << endl;
    }
}

int sum(const array<array<int, cols>, rows>& a) {
    int total = 0;

    for(const auto& row: a) {
        for(const auto& element: row) {
            total+=element;
        }
    }
    return total;
}