/*
    10. String to C-String
        - string1.c_str()

*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string string1{"STRINGS"};
    const char* ptr1{nullptr};

    size_t length{string1.size()};
    char* ptr2{new char[length+1]};

     cout << "string string1 is " << string1
      << "\nstring1 converted to a pointer-based string is "
      << string1.c_str()<< "\nptr2 is ";

    //length to copy and starting index
    string1.copy(ptr2, length, 0);
    //not it is not a null terminated yet
    ptr2[length] = '\0';

    //now you can directly print
    cout << ptr2 << endl;
}