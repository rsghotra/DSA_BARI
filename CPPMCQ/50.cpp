#include <iostream>
using namespace std;

/*
    Concept: static member functions
        - Declaring a static member does not create a memory space.
        - you must initialize them as well
    
*/

class Base {
    static int _x, _y;
public:
    void print() {cout << _x << " " << _y << endl; }
};

int Base::_x = 0;
int Base::_y = 0;

int main() {
    Base b1;
    b1.print();
    return 0;
}

