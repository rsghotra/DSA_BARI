/*
    String Class of C++ STL provide several library functions which can be categorized as:

    1. Assignment

    2. Concatenation

    3. Comparison

    4. Substrings

    5. Swapping Strings

    6. String Charactersitics

    7. Replacing Characters

    8. Inserting Characters

    9. Conversion to C-Strings

    10. Iterators

    11. String Stream Processing

    12. Numeric Conversions
*/

/*
    1. Assignment Methods
        a. at - perform bound checking
        b. assign ; // string3.assign(string1); // string3.assign(0, 3, string1)
        c [] - do not perform bound checking; string2[0] = string3[2] = 'r';
        d. = (copy constructor)
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string string1{"cat"};
    string string2;
    string string3; //initialized to an empty string

    string2 = string1; //assign string1 to string2
    string3.assign(string1);

    //modify string2 and string3; do not perform bound checking
    string2[0] = string3[2] = 'r';

    cout << "After modification of string2 and string3:\n" << "string1: " << string1
        << "\nstring2: " << string2 << "\nstring3: " << string3 << endl;

    //demonstrating member function at

    for(size_t i{0}; i < string3.size(); ++i) {
        cout << string3.at(i);
    }
}










