#include <iostream>
using namespace std;

/*
    Concepts: YOU CAN NOT CALL NON STATIC FUNCTIONS FROM A STATIC FUNCTION
    ``````````YOU CAN CALL STATIC FUNCTIONS FROM NON STATIC FUNCTIONS
         >==> STATIC FUNCTIONS
            - if call non-static functoin then COMPILE TIME ERROR
            - BECAUSE NON_STATIC FUNCTIONS WONT BE AVAILABLE FOR COMPILE TO BIND
        
*/

class Base{
    public:
       static void staticFun() {
           cout << " Static Fun" << endl;
           simpleFun();
       }
       void simpleFun() {
           cout << "Simple Fun" << endl;
       }
};

int main() {
    Base b;
    //will be evaluated at run time
    b.staticFun();
    return 0;
}


