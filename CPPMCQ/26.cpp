#include <iostream>
using namespace std;

/*
    Concept: Sequence of Constructor Calling: Parent is created then child is created
        - Base Consurctor
        - Child Constructor
        - Child Desctructor
        - Base Descrturtor
*/

class Base {
    public:
        Base() {
            cout << "Base()" << endl;
        }
        Base(int x) {
            cout << "Base(int x)" << endl;
        }
        ~Base() {
            cout << "~Base()" << endl;
        }
};

class Child: public Base {
public:
    Child(): Base() {cout << "Child()" << endl;}
    Child(int x): Base(x) { cout << "Child(int x)" << endl;}
    ~Child() {cout << "~Child()" << endl;}
};

int main() {
    //temporary objects
    Child();
    Child(1);
    return 0;
}

