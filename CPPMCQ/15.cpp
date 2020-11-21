#include<iostream>
using namespace std;

class Base {
    private:
        int _x;
    public:
        Base() {}
        Base(int x): _x{x}{}
        //internally it will be converted and gives us this pointers
        //Base(Base* this, int x): this->_x{x}{}
        //Every non-static function is modified by the compiler to include this pointer
        Base(const Base& obj) {_x = obj._x;}
        friend ostream& operator<<(ostream& os, const Base obj);
        friend ostream& operator<<(ostream& os, int obj);
};
//we usually do no want to have friend function  as part of base class
//operator<< is already present in the iostream we just overload it with our class obj
ostream& operator<<(ostream& os, const Base obj) {
            os << obj._x; // check this out - object is directly trying to access private member of the class
            //if you would want this this function must be declared Friend else compile time error
            return os;
}

//for example, overloading integer type obj tp print. This function is already present in iostream, hence compiler throw error
// ostream& operator<<(ostream& os, int obj) {
//             os << obj._x; // check this out - object is directly trying to access private member of the class
//             //if you would want this this function must be declared Friend else compile time error
//             return os;
// }

int main() {
    Base b1(10);
    Base b2 = b1;
    //line 28 implicitly converted to line 28 by compiler
    cout << b2 << endl;
    operator<<(cout, b2);
    cout << endl;
    cout << 10 << endl;
    return 0;
}