#include <iostream>
using namespace std;

/*
    Concept: Copy Consurctor & Assignment Operator
    //this will call copy constructor as we are creating and intializing as well
    Base b3 = b1; //creating and initializing
    //this will call assignment operator
    b2 = b1; //only assigning. B2 was already created
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
    //this will call copy constructor as we are creating and intializing as well
    Base b3 = b1;
    //this will call assignment operator
    b2 = b1;

    //this will call copy constructor as we are creating and intializing as well
    Base b4(b1);
    return 0;
}

