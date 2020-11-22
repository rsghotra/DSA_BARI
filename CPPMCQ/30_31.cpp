#include <iostream>
using namespace std;

/*
    Concept: REFERENCE DATA MEMBERS: USE INITIALIZER LIST TO INITIALIZE REFERENCE DATA MEMEBERS OF CLASS
                int& _x; and initializing
                    - Base(int x): { _x = x; } is going throw error
        Initializer List Usage: Base(int x): _x{x}{} will work

    INitializer List Usage:
        - Initialize constant data memeber
        - Initialize refernce data members
        

*/

class Base {
    int& _x;
public:
    Base(int x): _x{x}{}
    int getValue() {return _x;}
};

int main() {
    Base b(10);
    cout << b.getValue() << endl;
    return 0;
}

//A. 0
//B. 10
//C. Run T ime Error
//D. Compile Time Error
