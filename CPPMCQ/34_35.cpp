#include <iostream>
using namespace std;

/*
    Concept: Aggregation with BASE CONSUTRUCTOR CALL IN INITIALIZER LIST

    - When it come to initializer list - it is able to call constructor and we calling it directly
        Dase (int x): b{x} {}
    - Initialzier list calls the constructors on the object.
    - Therefore - in order to remove ambiguity:
        - Use Either this
        - Use Either Initializer list
*/

class Base {
    int x;
public:
    Base(int x): x{x}{}
    int getValue() { return x;}
};


int main() {
    Base b(10);
    cout << b.getValue() << endl;
    return 0;
}

//A. 10
//B. 0
//C. Run T ime Error
//D. Compile Time Error
