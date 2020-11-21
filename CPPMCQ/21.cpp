#include<iostream>
using namespace std;

/*
    Concept:
        - size of an empty class in C++ == 1
        - When the class is called empty - "WHEN A CLASS DO NOT HAVE ANY DATA MEMEBERS"
        - size of empty class in C == 0
*/

class Base {
    Base() {}
    Base(int x) {}
    Base(int x, int y) {}
};

int main() {
    cout << sizeof(Base) << endl;
    return 0;
}