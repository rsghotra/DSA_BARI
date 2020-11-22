#include <iostream>
using namespace std;

/*
    Concept: Different format of Constructor:
        - C-Style Structure Copy:
            //this is C-Style Structure Copying is happening
            Base a = {10};
            - MAKE SURE DATA MEMEBER IS PUBLIC - 
            - BECAUSE ALL DATA MEMBERS OF A STRUCTURE IS PUBLIC
        - IN THIS DATA MEMEBER IS PRIVATE - SO CODE IS INVALID
*/

class Base {
    int x;
public:
    int getValue() { return x;}
};


int main() {
    //this is C-Style Structure Copying is happening
    Base a = {10};
    Base b = a;
    cout << a.getValue() << " " << b.getValue() << endl;
    return 0;
}

//A. 10 10
//B. 10 0
//C. Run T ime Error
//D. Compile Time Error