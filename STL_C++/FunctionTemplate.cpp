#include<iostream>
#include<iomanip>
#include "maximum.h"
using namespace std;

int main() {
    cout << "Input three integr values: ";
    int int1, int2, int3;
    cin >> int1 >> int2 >> int3;

    cout << "The maximum integer value is "
        << maximum(int1, int2, int3);

    cout << "\nEnter three double values: ";
    double double1, double2, double3;
    cin >> double1 >> double2 >> double3;

    char char1, char2, char3;
    cout << "Enter three characters: ";
    cin >> char1 >> char2 >> char3;
    cout << "The maximum character value is: " << maximum(char1, char2, char3);
}

