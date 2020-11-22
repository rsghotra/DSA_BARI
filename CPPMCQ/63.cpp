#include <iostream>
using namespace std;

/*
    Concept: Friend Class 
        - The class which is not present here can be declared friend class
        - Non existent/non-visible classes could be declared as friend function / class 
        
*/

class Base {
    private:
    //it is not even visible but still compiler will allow it

        friend class MyClass;
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
