/*
    6. String characterstics
        a. capacity()
        b. size()
        c. max_size()
        d. resize()
*/
#include<iostream>
#include<string>
using namespace std;

void printStatistics(const string&);

int main() {
    string string1;

    cout << "Statistics before input:\n" << boolalpha;
    printStatistics(string1);

    cout << "\n\nEnter a string: ";
    cin >> string1;
    cout << "The string entered was: " << string1;

    cout << "\nStatistics after input:\n";
    printStatistics(string1);

    string1.resize(string1.size() + 10);

    cout << "\n\nStats after resizing by (length + 10):\n";
    printStatistics(string1);
    cout << endl;
}

void printStatistics(const string& stringRef) {
    cout << "capacity: " << stringRef.capacity() << "\nmax size: "
        << stringRef.max_size() << "\nsize: " << stringRef.size()
        << "\nlength: " << stringRef.size()
        << "\nempty: " << stringRef.empty();
}