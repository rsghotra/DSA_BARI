#include <iostream>
using namespace std;

/*
    Concept:  Temporay Objects are consutructed and destructed in same line
        :Line 24 and Line 25 are not initialized.
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
    //temporary objects because not assigning to any variable
    //temporary objects are created and destructed in same line
    Base();
    Base(1);
    return 0;
}