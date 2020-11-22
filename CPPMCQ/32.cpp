#include <iostream>
using namespace std;

/*
    Concept: Aggregation does not allow private members to ve accessed outside of class
    See line 22

*/

class Base {
    int _x;
public:
    Base() {}
    Base(int x): _x{x}{}
    int getValue() {return _x;};
};

class Bingo {
    Base b;
public:
 // problem line b object is trying to directlu access
    Bingo (int x) {b._x = x;}
    Base& getBase() { return b;}
};

int main() {
    Bingo b(10);
    cout << b.getBase().getValue() << endl;
    return 0;
}

//A. 10
//B. 0
//C. Run T ime Error
//D. Compile Time Error
