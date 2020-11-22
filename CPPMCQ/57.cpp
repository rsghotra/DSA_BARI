#include <iostream>
using namespace std;

/*
    Concept: Global Scope & Namespaces
        ::using scope resolution - you can force global scope
    - Namespace CAN NOT BE IN LOCAL SCOPE MEANS IN NAME OR ANY OTHER FUNCTION
*/

namespace  MyNameSpace
{
    int _x = 15;    
} 
int _x = 10;

class Number {
    int x, y;
public:
    Number(): Number(0,0) {
        cout << 0;
    }
    Number(int a): Number(a, 0) {
        cout << 1;
    }
    Number(int a, int b): x{a},y{b} {
        cout << 2;
    }
};

int main() {
    // namespace  MyNameSpace
    
    {
        int _x = 20;
        cout << _x << endl;
        cout << MyNameSpace::_x << endl;
        cout << ::_x << endl;
    }
    Number n1;
    Number n2 = 10;
    Number n3 = {10, 20};
    return 0;
}

//O/P -15 15