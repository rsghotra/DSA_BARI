#include<iostream>
#include<iomanip>
using namespace std;

void useLocal(); //function prototype
void useStaticLocal();
void useGlobal();

int x{1};

int main() {
    cout << "global x in main is " << x << endl;
    int x{5}; //local variable to main
    cout <<"local x in main's outer scoper is " << x << endl;

    {
        //block starts a new scope
        int x{7}; //hides both x in pouter scope and global x
        cout << "local x is main's inner scope " << x << endl;
    }
    cout << "local x in main's outer scope is " << x << endl;

    useLocal();
    useStaticLocal();
    useGlobal();

    useLocal(); //reinitialize its local x
    useStaticLocal(); //static local retail its prior value
    useGlobal(); //global x also retains its prior value

    cout << "\nlocal x in main is " << x << endl;
}

void useLocal() {
    int x{25}; //initialized each time useLocal is called

    cout << "\nLocal x is " << x << " on entering useLocal" << endl;
    ++x;
    cout <<"local x is " << x << " on exiting useLocal" << endl;
}

void useStaticLocal() {
    static int x{30}; //interesting - initialized only when first time useStaticLocal is called
    cout << "\nlocal static x is " << x << " on entering useStaticLocal" << endl;
    ++x;
    cout << "local static x is " << x << " on exiting useStaticLocal" << endl;
}

//useGlobal modifies gloabl variable during each call

void useGlobal() {
    cout << "\nglobal x is " << x << " on entering useGlobal" << endl;
    x*=10;
    cout << "global x is " << x << " on exiting useGlobal" << endl;
}

