#include <iostream>
using namespace std;

/*
    Concept: const data memeber
        - const member must be initialized using intialzer list or 
        at the same tine of creating them
    
*/

class Base {
    const int _x, _y;
public:
    void print() {cout << _x << " " << _y << endl; }
};

int main() {
    Base b1;
    b1.print();
    return 0;
}

