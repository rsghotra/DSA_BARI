/*
    2. Comparison - Lexicographic
        a. <, >, ==, >=, <=
        b. .compare
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string string1{"Testing the comparison functions."};
    string string2{"Hello"};
    string string3{"stinger"};
    string string4{string2};

    cout << "string1: " << string1
        << "\nstring2: " << string2 << "\nstring3: " << string3 
        << "\nstring4: " << string4 << "\n\n";

    if(string1 == string4) {
        cout << "\nstring1 == string4\n";
    } else if(string1 > string4) {
        cout << "\nstring1 > string4\n";
    } else {
        cout << "\nstring1 < string4\n";
    }

    int result{string1.compare(string2)};

    if(result == 0) {
        cout << "\nstring1.compare(string2) == 0\n";
    } else if(result > 0) {
        cout << "\nstring1.compare(string2) > 0\n";
    } else {
        cout << "\nstring1.compare(string2) > 0\n";
    }

    //ranged comparison

    result = string1.compare(2,5,string3,0,5);
    if(result == 0) {
        cout << "\nstring1.compare(2,5,string3,0,5) == 0\n";
    } else if(result > 0) {
        cout << "\nstring1.compare(2,5,string3,0,5) > 0\n";
    } else {
        cout << "\nstring1.compare(2,5,string3,0,5) > 0\n";
    }

    result = string4.compare(0, string2.size(), string2);
    if(result == 0) {
        cout << "\nstring4.compare(0, string2.size(), string2) == 0\n";
    } else if(result > 0) {
        cout << "\nstring4.compare(0, string2.size(), string2) > 0\n";
    } else {
        cout << "\nstring4.compare(0, string2.size(), string2) > 0\n";
    }

}