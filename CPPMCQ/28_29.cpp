#include <iostream>
using namespace std;

/*
    Concept: Constant Data Members: You must use INITIALIZER 
        - Initializing constant data memeber through constructor is not allowed like this:
            Base(int x): {_x = x;}
        - YOU MUST USE INITIALIZER LIST TO INITIALIZE THE CONSTANT DATA MEMEBERS
            Base(int x): _x{x}{}
        - THIS IS ONE OF THE PURPOSE OF CREATING INITIALIZER LIST

*/

class Base {
    const int _x;
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

