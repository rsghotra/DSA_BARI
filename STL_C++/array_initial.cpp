#include<iostream>
#include<iomanip>
#include<array>

using namespace std;

int main() {
    /*
        - Array declaration and initialization using for loop
    */
    array<int, 5> n;

    for(size_t i{0}; i < n.size(); ++i) {
        n[i] = 0;
    }
    //
    cout << "Element" << setw(10) << "Value" << endl;
    for(size_t j{0}; j < n.size(); ++j) {
        cout << setw(7) << j << setw(10) << n[j] << endl;
    }

    //initializing using initializer list
    array<int, 6>n2{10,15,20,25,30};
    cout << "Element" <<setw(10) << "Value" << endl;
    for(size_t i{0}; i < n2.size(); ++i) {
        cout << setw(7) << i << setw(10) << n2[i] << endl;
    }

    //array of const size
    const size_t arraySize = 5;
    array<int, arraySize> n3{}; //initialized to zero all elements
    for(size_t i{0}; i <  n3.size(); ++i) {
        n3[i] = 2 + 2 * i;
    }

    cout << "Element" <<setw(10) << "Value" << endl;
    for(size_t i{0}; i < n3.size(); ++i) {
        cout << setw(7) << i << setw(10) << n3[i] << endl;
    }

    size_t total{0};

    for(size_t i{0}; i < n3.size(); ++i) {
        total += n3[i];
    }

    cout << "Total of Array Elements: " << total << endl;

    return 0;
}