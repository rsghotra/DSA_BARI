/*
    2. Concatentaion
        a. +=
        b. append
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string string1{"cat"};
    string string2;
    string2 = string1 + "apult";
    
    string string3{string1 + "apult"};

    string3 += "pet";

    string1.append("acomb");

    string string4;
    string4.append(string1, 4, string1.size() - 4);

    cout << "After concatenation:\n" << "string1: " << string1
        << "\nstring2: " << string2 << "\nstring3: " << string3 
        << "\nstring4: " << string4 << endl;
}