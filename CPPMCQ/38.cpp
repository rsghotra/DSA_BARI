#include <iostream>
using namespace std;

/*
    Concept: Different Styles of Calling Constructors
        - This will work because Base has only one data member
        - Base a = 10; // compiler will automaticall change it to Base a = {10}
*/

class Base {
    int x;
public:
    Base(int x): x{x} {}
    int getValue() { return x;}
};


int main() {
    Base a = 10;
    Base b = a;
    cout << a.getValue() << " " << b.getValue() << endl;
    return 0;
}

//A. 10 10
//B. 10 0
//C. Run T ime Error
//D. Compile Time Error