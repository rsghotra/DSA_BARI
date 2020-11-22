#include <iostream>
using namespace std;

/*
    Concept: Initialize by garbage value; Scope; Global Variable

*/

int _x = 10;

class Base {
    int _x, _y;
    public:
        void print() {
            cout << _x << " " << _y << endl;
        }
};

int main() {
    Base b1;
    b1.print();
    return 0;
}

