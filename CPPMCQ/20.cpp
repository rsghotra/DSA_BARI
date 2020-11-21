#include <iostream>
using namespace std;

/*
    Concept:
        - 
*/

class Base {
    int _x;
    public:
        Base() {}
        Base(int x) {
            _x = x;
            cout << "Base Initialize x" << endl;
        }
};

class Child: public Base {
    int _y;
public:
    Child(): Base() {}
    Child(int x, int y): Base(x){ 
        _y = y;
        cout << "Child initialize and y" << endl;
    }
};

int main() {
    Child c1(1,2);
    //line 29 no default consurctor
    Child c2;
    c2 = c1;
    return 0;
}

