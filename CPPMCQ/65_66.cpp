#include <iostream>
using namespace std;

/*
    Concepts: 
         >==> Virtual CONSTRUCTOR: C++ DOES NOT ALLOW VIRTUAL CONSTRUCTOR
            - C++ - you can not construct object VIRTUALLY
        >==> C++ allows Virtual Destructor used to ensure proper object deletion when
                polymorphism is used and Base class ptr is pointing to derived class
                Ex:
                    Base* p = new Derived();
                    delete p;
                    //at this time first - derived class destructor - constructor
            - Why we need VD
        
*/

class Base{
    public:
        virtual Base() {
            cout << "Constructor" << endl;
        }
        virtual ~Base() {
            cout << "Destructor" << endl;
        }
};

int main() {
    Base* b = new Base();
    delete b;
    return 0;
}
