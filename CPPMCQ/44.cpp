#include <iostream>
using namespace std;

/*
    Concept: Creating Base Object in Base Constructor

*/

class Base {
    int _x, _y;
    public:
        Base() {}
        Base(int x, int y) {
            Base b;
            b._x = x;
            b._y = y;
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

