#include <iostream>
using namespace std;

/*
    Concept: Creating Base Object in Base Constructor
        - BAD - RECURSIVE CALL

*/

class Base {
    int _x, _y;
    public:
        Base() {}
        Base(int x, int y) {
            Base b(x, y);  //<== problematic call
            b.print();
            *this = b;
        }
        void print() {
            cout << _x << " " << _y << endl;
        }
};


int main() {
    Base b(10,20);
    b.print();
    return 0;
}

