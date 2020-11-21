 #include <iostream>
using namespace std;

/*
    Concept - Static class members MUST BE INITIALIZED OUTSIDE OF CLASS IN ORDER TO MAKE
                THEM BEHAVE STANDARD
            - 
*/

class Base {
    //only declration; IT JUST DOES NOT HAVE SPACE IN MEMORY LOL
    static int _x;
    public:
        Base(int x) {_x = x;}
        int getValue() {return _x;}
};

int Base::_x;

int main() {
    Base b(10);
    cout << b.getValue() << endl;
    return 0;
}
