#include <iostream>
using namespace std;

/*
    Concepts: 
         >==> STATIC FUNCTIONS
        
*/

class Base{
    public:
       static void staticFun() {
           cout << " Static Fun" << endl;
       }
       void simpleFun() {
           cout << "Simple Fun" << endl;
       }
};

int main() {
    Base b;
    b.simpleFun();
    //this b.staticFun() will be eval at run time
    b.staticFun();
    //this will be eval at compile time
    Base::staticFun();
    return 0;
}


