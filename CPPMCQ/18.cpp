 #include <iostream>
using namespace std;

/*
    Concept - POSITIONING OF BASE CONSTRUCTOR CALL WONT MATTER
            - ONLY THING IS Base CONSUTRUCTOR MUST BE MANUALLY CALLED BY CHILD CONSTRUCTOR
            - If you are not calling base function then there is no need to bother
*/

class Base {
    int _x;
    public:
        //Base() {}
        Base(int x): _x{x} {cout << "Base Initialize x" << endl;}
};

class Child: public Base {
    int _y;
    public:
    Child(int x, int y):_y{y}, Base{x}{
        cout << "Child initialize and y" << endl;
    }
};

int main() {
    Child c1(1,2);
    return 0;
}

