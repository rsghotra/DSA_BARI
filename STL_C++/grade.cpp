#include<iostream>
#include<array>
using namespace std;

//Bar chart printing program

int main() {
    const size_t arraySize{11};
    array<unsigned int, arraySize> n{0,0,0,0,0,0,1,2,4,2,1};

    cout << "Grade distribution: " << endl;
    for(size_t i{0}; i < n.size(); ++i) {
        if(i == 0) {
            cout << "0-9: ";
        }
        if(i == 10) {
            cout << "  100: ";
        }
        else {
            cout << i * 10 << "-" << (i*10)+9 << ": ";
        }

        for(size_t j = 0; j < n[i]; ++j) {
            cout << "*";
        }

        cout << endl;
    }
}