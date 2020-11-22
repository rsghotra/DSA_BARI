#include <iostream>
using namespace std;

/*
    Concept: Class semicolon is missing
        
*/

class Base {
    public:
        void fun() {
            cout << "I Love C++" <<endl;
        }
};

int main() {
    Base* b = new Base();
    b->fun();
    delete b;
    return 0;
}
