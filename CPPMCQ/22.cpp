#include<iostream>
using namespace std;
#pragma pack(1) //enforces compiler to not use PADDING

/*
    Concept: Empty Class: A class which do not have any data members
        - If class do not have any data memeber then class size is 1
        - if class do have any data memeber then class size is equal to size of data memeber
        - size of an empty class in C++ == 1
        - When the class is called empty - "WHEN A CLASS DO NOT HAVE ANY DATA MEMBERS"
        - size of empty class in C == 0
*/

class Base {
    //size of class = 1 as there is no data memeber
    //now after adding data member = size of class is 1 still
    char ch;
    public:
    Base() {}
    Base(int x) {}
    Base(int x, int y) {}
};

class Child: public Base {
    //size of class = 4 from itself; 1 from base class+3 from structural paddding
    int _x;
};

int main() {
    //structural padding results in size 8; If #pragma pack(1)  is used then
    cout << sizeof(Base) << " " << sizeof(Child) << endl;
    //OP is 1 and 4
    return 0;
}