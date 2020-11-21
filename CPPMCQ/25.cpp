#include <iostream>
using namespace std;

/*
    Concept:  Standard constructor and desctructor calls fpr permanent objects
*/

class Base {
    public:
        Base() {
            cout << "Base()" << endl;
        }
        Base(int x) {
            cout << "Base(int x)" << endl;
        }
        ~Base() {
            cout << "~Base()" << endl;
        }
};

//WOW
int main() {
    //These are called permanent objects
    Base b1 = Base();
    Base b2 = Base(1);
    Base();
    return 0;
}