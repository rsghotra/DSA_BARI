#include<iostream>
#include<iomanip>
#include<array>
using namespace std;

void staticArrayInit();
void automaticArrayInit();

const size_t arraySize{3};

int main() {
    cout << "First call to each function:\n";
    staticArrayInit();
    automaticArrayInit();

    cout << "\nSecond call to each function:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << endl;
}

void staticArrayInit(void) {
    //c++ initialized the static array elemented to 0
    static array<int, arraySize> array1;
    cout << "\nValues on entereing staticArrayInit:\n";
    for(size_t i{0}; i<arraySize;++i) {
        cout << "array["<<i<<"] = "<<array1[i] << " ";
    }
    cout << "\nValues on exiting staticArrayInit:\n";
    for(size_t i{0}; i<arraySize;++i) {
        cout << "array["<<i<<"] = "<<(array1[i]+=5) << " ";
    }
}

void automaticArrayInit() {
    array<int, arraySize> array2{1,2,3};
    cout << "\nValues on entereing automaticArrayInit:\n";
    for(size_t i{0}; i<arraySize;++i) {
        cout << "array["<<i<<"] = "<<array2[i] << " ";
    }
    cout << "\nValues on exiting automaticArrayInit:\n";
    for(size_t i{0}; i<arraySize;++i) {
        cout << "array["<<i<<"] = "<<(array2[i]+=5) << " ";
    }
}