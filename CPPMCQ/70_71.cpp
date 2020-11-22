#include <iostream>
using namespace std;

/*
    Concepts: Interface & Virtual keyword - IF VIRTUAL KEYWORD IS NOT THERE THEN
        WE WILL ALWAYS END UP CALLING BASE CLASS FUNCTION
        - VIRTUAL DELAYS THE BINDING UTLI RUN TIME
        - Virtual Keyword tells the compiler - do not decide what is the type of object
        - Instead wait until last moment and call calling object's corresponding function
        
*/

class Base {
    public:
        virtual void myFun() {cout << "Base" << endl;}
}base;

class D1: public Base {
    public:
        void myFun() {cout << "D1" << endl;}
}d1;

class D2: public Base {
    public:
        void myFun() {cout << "D2" << endl;}
}d2;

Base& interface(int x) {
    if(x) return d1;
    else return d2;
}

int main() {
    Base b;
    interface(1).myFun();
    interface(0).myFun();
    return 0;
}