#include <iostream>
using namespace std;

/*
    Concept: Constructor Call Sequence & MAIN CALL Seqence:
        - Global variables are called before MAIN

        Global Variables -> Main -> Functions 
    O/P: Base1 Called -> Main Called -> Base2 Called

*/

class Base1
{
    public:
        Base1() {
            cout << "Base1 Called" << endl;
        }
}b; //global variables

class Base2
{
    public:
        Base2() {
            cout << "Base2 Called" << endl;
        }
};

int main() {
    cout << "main called" << endl;
    Base2 b2;
    return 0;
}

