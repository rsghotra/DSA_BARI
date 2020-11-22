#include <iostream>
using namespace std;

/*
    Concept: Consutrctor and Inheritence
    //Private members are not inherited
    //Using intiliaer list - you need to call base consurtuictor

*/

class BaseNumber {
    int _x;
    public:
        BaseNumber(int x): _x{x} {cout << 2;}
};


class Number: public BaseNumber {
    int _y;
public:
    Number(): _y{0}, BaseNumber(0) {cout << 0;}
    Number(int a, int b): _y{b},BaseNumber{a} {cout << 1;}
};

int main() {
    Number n1;
    Number n2 = {10, 20};
    return 0;
}