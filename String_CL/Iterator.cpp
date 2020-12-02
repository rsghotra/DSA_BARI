/*
    11. Iterators
        - Forward iterator
        - Backward iterator
        - iterators are not ranged checked! - You have to put it
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string string1{"Testing iterators"};
    string::const_iterator iterator1{string1.begin()};

    cout << "string1 = " << string1
        << "\n(Using iterator iterator1) string1 is: ";

    //iterator through string
    while(iterator1 != string1.end()) {
        cout << *iterator1;
        ++iterator1;
    }

    cout << endl;
}