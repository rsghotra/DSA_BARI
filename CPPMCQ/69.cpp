#include <iostream>
using namespace std;

/*
    Concepts: Same signature for functions
        
*/

class Base{
    public:
       char fun() {
           return 'C';
       }
       int fun() {
           return 10;
       }
};

int main() {
    Base b;
    cout << b.fun() << endl;
    return 0;
}


