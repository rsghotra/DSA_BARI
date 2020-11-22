#include <iostream>
using namespace std;

/*
    Concept: Initialize by garbage value

*/

class Base {
    int _x, _y;
    public:
        //y has garbage value right now
        Base(int val):_x{_y+1}, _y{val+1} {}
        void print() {
            cout << _x << " " << _y << endl;
        }
};

int main() {
    Base b1(5);
    b1.print();
    return 0;
}

