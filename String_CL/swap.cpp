/*
    5. Swap
        a. swap: first.swap(second); //in-place swap
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string first{"one"};
    string second{"two"};

    cout << "Before swap:\nfirst: " << first << "\nsecond: " << second;

    first.swap(second);
    cout << "After swap:\nfirst: " << first << "\nsecond: " << second;

}