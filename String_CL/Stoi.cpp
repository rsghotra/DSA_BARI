/*
    13. Numeric Conversion of String objects

            1. Numeric to String Object:
                a. to_string(numeric_value)
            2. String to Numeric:
                a. Function to convert String to integer
                    1. stoi
                    2. stol
                    3. stoul
                    4. stoll
                    5. stoull
                b. Function to convert String to floating value
                    1. stof
                    2. stod
                    3. stold
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1{"100.2hello"};

    int convertedInt = stoi(s1);
    // stoi(s1, nullptr, <base_system>)

    int convertedBinary = stoi(s1, nullptr, 2);

    cout << s1 << ": " << convertedInt << endl;

    double convertedDouble = stod(s1);

    cout << s1 << ": " << convertedDouble << endl;
}