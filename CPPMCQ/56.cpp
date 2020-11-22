#include <iostream>
using namespace std;

/*
    Concept: Global Scope & Namespaces
        ::using scope resolution - you can force global scope
        cout << ::_x << " "; -- access global x
        cout << myspace::_x << -- [rp[er access]]
*/

namespace MySpace {
    int _x = 10;
}

int _x = 55;

int main() {
    int _x = 15;
    {
        int _x = 20;
        cout << ::_x << " ";
    }
    cout << _x << endl;
    return 0;
}

//O/P -15 15