#include<iostream>
using namespace std;



/*
    Concept: 
*/

class Base {
    public:
        Base() {cout << "Base()" << endl;}
        Base(int x) {cout << "Base(int x)" << endl;}
        Base(int x, int y) {cout << "Base(int x, int y)" << endl;}
};


int main() {
    Base();
    Base(1);
    Base(1,2);
    return 0;
}
