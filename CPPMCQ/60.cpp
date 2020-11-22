#include <iostream>
using namespace std;

/*
    Concept: Consutrctor Delegation and Private Constructor
        - Not All constructors can be private
        - there must atleast be one public constructor
*/

class Base {
    int _x;
    Base(int x): _x{x} {cout << 1;}
public:
    Base():Base(0) {cout << 0;}
};

int main() {
    Base b;
    return 0;
}

//O/P: 10
