#include<iostream>
#include<iomanip>
#include<array>

using namespace std;

int main() {
    /*
        - Array declaration and initialization using for loop
    */
    const size_t arraySize{5};
    array<int,arraySize> n;
    //array initialization using for loop
    for(size_t i{0}; i<arraySize; ++i) {
        n[i] = 0;
    }

    cout << "Element" << setw(10) << "Value" << endl;

    for(size_t j{0}; j < arraySize; ++j) {
        cout << setw(7) << j << setw(10) << n[j] << endl; 
    }

    array<int, arraySize +1> n2{2,3,4,5,6};
    int sum{0};
    cout << "Element" << setw(10) << "Value" << endl;
    for(size_t k{0}; k < arraySize+1; ++k) {
        cout << setw(7) << k << setw(10) << n2[k] << endl;
        sum+= n2[k];
    }
    cout << "Total of array elements: " << sum << endl;
    return 0;
}