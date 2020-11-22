#include <iostream>
using namespace std;

/*
    Concept: Empty class - malloc keyword effect

    WOW - 
    - MALLOC KEYWORD DOES NOT CALL THE CONSTRUCTOR
    - IT IS A RAW MEMORY ALLOCATION
    - Freestore is the new name for C++ in Heap
    - NEW KEYWORD CALL THE CONSUTRUCTOR - MALLOC KEYWORD DOES NOT
*/

class Base {
public:
    Base() {
        cout << "Constructor Called." << endl;
    }
};


int main() {
    //this will not call the constructor
    Base *t1 = (Base*) malloc(sizeof(Base));
    //this will CALL constructor
    Base *t2 = new Base();
    return 0;
}