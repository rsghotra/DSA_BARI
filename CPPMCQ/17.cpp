#include <iostream>
using namespace std;

class Base {
    int _x;
    public:
        //Base() {}
        Base(int x): _x{x} {cout << "Base Initialize x" << endl;}
};

class Child: public Base {
    int _y;
    public:
    //child class can not automatic access to private members of the base class
    //child class must call base class constructor explicitly
    //Therefore line 16 in comments is not correct.
        //Child(int x, int y): _x{x}, _y{y} {cout << "Child Initialize x and y" << endl;}

    //You must call base constructor class explicitly.
    //Child(): Base() {}
    Child(int x, int y): Base{x}, _y{y}{
        cout << "Child initialize and y" << endl;
    }
};

int main() {
    Child c1;
    Child c2(1,2);
    return 0;
}

