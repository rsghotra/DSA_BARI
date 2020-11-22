#include <iostream>
using namespace std;

/*
    Concept: Polymorphism
        - This is what is looks like when non-polymorphic behavior
        -   myFun(new Derived);
            myFun(new Base);
                Both will call base class function because Line 28 has pointer type Base


*/

class Base {
    public:
        void myFun() {
            cout << "Base MyFun" << endl;
        }
};

class Derived: public Base {
    public:
        void myFun() {
            cout << "Derived MyFun" << endl;
        }
};

void myFun(Base* b) {
    b->myFun();
    delete b;
}

int main() {
    myFun(new Derived);
    myFun(new Base);
    return 0;
}

