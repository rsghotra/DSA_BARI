#include<iostream>
#include<iomanip>
using namespace std;

//string objects are usually heavy therefore should pass by reference.
int number{7};
int squareByValue(int);
void squareByReference(int&);


int main() {
    int x{2};
    int z{4};
    //demo square by value
    cout << "x= " << x << " before squareByValue\n";
    cout << "Value returned by squareByValue: "
        << squareByValue(x) << endl;
    cout << "x= " << x << " after squareByValue\n" << endl;

    //demo squareByReference
    cout << "z= " << z << " before squareByReference" << endl;
    squareByReference(z);
    cout << "z= " << z << " after squareByReference" << endl;
    double number{10.5};
    cout << "Local double value of number " << number
        << "\nGlobal int value of number " << ::number << endl;
    return 0;
}

int squareByValue(int number) {
    return number*= number;
}

void squareByReference(int& number) {
    number *= number;
}
