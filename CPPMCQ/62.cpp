#include <iostream>
using namespace std;

/*
    Concept: Friend Class + Scope Resolution Operator
        - It is used to bring the base class function to derived class for usage
        - scope resolution opertor
*/

class Base {
    private:
        friend class Derived;
        void wow() {cout << "Base private wow";}
    public:
        void fun() {
            cout << "base public fun" <<endl;
        }
};

class Derived: public Base {
    public:
        void wow() {
            //wow is a private function of base class. 
            //therefore even a scope resolution operator won't be able to help it
            //we must declare the class as friend class
            Base::wow();
        }
        void fun() {
            //scope resolution - bringing in base class function
            Base::fun();
        }
};

int main() {
    Derived* d = new Derived();
    d->fun();
    d->wow();
    delete d;
    return 0;
}
