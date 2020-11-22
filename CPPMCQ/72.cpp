#include <iostream>
using namespace std;

/*
    Concepts: Object Slicing
        - In C++ - Derived class object can be assigned to object of Base Class.
            - Derived d; Base b = d; //correct - Object Slicing occuring
            - Base b; Derived d = b; //incorrect
        - Object slicing occurs when you assign object of a derived class to 
            object of base class - causing information loss of derived class object
        - We can avoid above unexpected behavior with the use of pointers or references. 
        - Object slicing doesn’t occur when pointers or references to objects are passed 
            as function arguments since a pointer or reference of any type takes same 
            amount of memory.
        
        
*/

class A{
    int x;
};
class B: public A{
    int y;
};

int main() {
    //what should be done here to achieve object slicing
    B b;
    // ONLY A part of B will be copied rest will be sliced off
    A a = b;
    return 0;
}