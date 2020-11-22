#include <iostream>
using namespace std;

/*
    Concept: Friend Function Access Power Do to Translato to Base Class
    - Friendship is not extended to base class.
    - Whatever Derived class can access - its friend function can access
    - For example -
            1. Derived class CAN NOT access Base Class' private function so do the friend function
            2. Derived class CAN ACCESS BASE CLASS's PROTECTED MEMEBER FUNCTION SO DO FRIEND FUNCTION OF DERIVED CLASS
*/

class Base {
    //making protected so that Derived and consequentally friend can access it
    protected:
        int b;
};

class Derived: public Base {
    int d;
    friend void fun(Derived &);
};

void fun(Derived &obj) {
    obj.b = 10;
    obj.d = 20;

    cout << obj.b << " " << obj.d << endl;
}

int main() {
    Derived d;
    fun(d);
    return 0;
}

//A. 10 20
//B. 20 10
//C. Run T ime Error
//D. Compile Time Error

