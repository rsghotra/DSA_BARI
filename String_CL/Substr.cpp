/*
    3. Substring
        a. substr: string1.substr(startIndex, numberofChars); produce a new string
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string string1{"The airplane landed on time."};

    cout << string1.substr(7,5) << endl;
}