/*
    12. String Stream Processing
        - istringstream; >>; reading from string
        - ostringstream; <<; reading into string
        - Backward iterator
        - iterators are not ranged checked! - You have to put it
*/
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main() {
    string input{"Input test 123 4.7 A"};
    
    istringstream inputString{input};

    string string1;
    string string2;
    int integer;
    double double1;
    char character;

    inputString >> string1 >> string2 >> integer >> double1 >> character;

    cout << "The following items were extracted\n"
      << "from the istringstream object:" << "\nstring: " << string1
      << "\nstring: " << string2 << "\n   int: " << integer
      << "\ndouble: " << double1 << "\n  char: " << character;
    
    //now the stream is empty
    long value;
    inputString >> value;

    if(inputString.good()) {
        cout << "\n\nlong value is: " << value << endl;
    } else {
        cout << "\n\ninputString is empty" << endl;
    }

    ostringstream output;

    string string12{"Output of several data types "};
    string string22{"to an ostringstream object:"};
    string string3{"\n        double: "};
    string string4{"\n           int: "};
    string string5{"\naddress of int: "};

    double double2{123.4567};
    int integer2{22};

    output << string12 << string22 << string3 << double2 
        << string4 << integer2 << string5 << &integer;
    
    cout <<"outputString contains:\n" << output.str();

    output << "\nmore characters added";                
    cout << "\n\nafter additional stream insertions,\n"
      << "outputString contains:\n" << output.str() << endl;
}