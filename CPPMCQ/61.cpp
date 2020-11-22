#include <iostream>
using namespace std;

/*
    Concept: Bringing in function of base class into scope and usage in Derived class
        - scope resolution opertor
*/

class Base {
    private:
        void fun() {
            cout << "private" <<endl;
        }
};

class Derived: public Base {
    public:
        void fun() {
            //scope resolution - bringing in base class function
            this::Base->fun();
        }
};

int main() {
    Derived* d = new Derived();
    d->fun();
    delete d;
    return 0;
}
