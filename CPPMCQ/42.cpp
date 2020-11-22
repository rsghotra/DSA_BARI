#include <iostream>
using namespace std;

/*
    Concept: Copy Constructor
    - When to write copy constructor


*/

class Base
{
    int _x;
    public:
        Base() {}
        Base(int x): _x{x}{}
        Base(const Base& rhs) { //copy constructor
            _x = rhs._x;
        }
};

int main() {
    Base b1;
    Base b2 = b1;
    return 0;
}

