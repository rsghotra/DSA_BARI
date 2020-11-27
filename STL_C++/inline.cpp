#include<iostream>
#include<iomanip>
using namespace std;

inline double cube(const double side) {
    return side * side * side;
}

int main() {
    double sideValue;
    cout << "Enter th eside length of the cube: ";
    cin >> sideValue;

    cout << "Volume of cube with side " << sideValue << " is " << cube(sideValue) << endl;
}