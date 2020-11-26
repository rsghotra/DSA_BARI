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
    return 0;
}