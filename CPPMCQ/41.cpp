#include <iostream>
using namespace std;

/*
    Concept: Explicit
        Explicit keyword forbid alternative calls of constructors or implicit calls
        for example:
            Base a = 10;

            You must do this : Base a(10);
            Having explict allow us to force the user to explicityly call consutrcustoc
        - EXPLICIT keyword help us removing confusin


*/

class Base
{
    int x;
    public:
        explicit Base(int x): x{x}{}
        int getValue() { return x;}
};

int main() {
    //c-style struct copy will not be allowed if explict consurctor is used
    //Base a = 10;
    Base a(10);
    Base b = a;
    cout << a.getValue() << " " << b.getValue() << endl;
    return 0;
}

