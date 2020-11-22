#include <iostream>
using namespace std;

/*
    Concept: Copy Consurctor & Assignment Operator
    
*/

class Base {
    int _x;
public:
    Base(): _x{0} {}
    Base(const Base & rhs) { //copy constructor
        _x = rhs._x;
        cout << "Copy Constructor" << endl;
    }
    Base& operator=(const Base& rhs) {
        _x = rhs._x;
        cout << "Assignment operator" << endl;
        return *this;
    }
};

int main() {
    Base b1, b2;
    Base b3(b1);
    return 0;
}

