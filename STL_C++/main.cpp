#include<iostream>
#include<iomanip>
#include<array>
#include<string>
#include<algorithm>
using namespace std;

/*
    - void sort(array.begin(), array.end())
        - Sort specifies the range of elements which needed to
            be sorted
    - bool binary_search(array.begin(), array.end(), key)
        - binary_search only tells us if the element is present
            or not. It does not give us the positoin of the array
    - int find(array.begin(), array.end() gives us the postion loactaion)
*/

int main() {
    const size_t arraySize{7};
    array<string, arraySize> colors{"red","orange","yellow","green",
        "blue", "indigo", "violet"};

    cout <<"Output Original Array: \n";
    for(string color: colors) {
        cout << color << " ";
    }
    cout << endl;
    sort(colors.begin(), colors.end());

    //output sorted array
    cout <<"\nSorted array:\n";
    for(string color: colors) {
        cout << color << " ";
    }
    cout << endl;

    bool found{binary_search(colors.begin(), colors.end(), "indigo")};
    if(found) {
        cout << "\n\nindigo found in colors" << endl;
    } else {
        cout << "\n\nindigo was not found in colors" << endl;
    }
    found = binary_search(colors.begin(), colors.end(), "cyan");
    if(found) {
        cout << "\ncyan found in colors" << endl;
    } else {
        cout << "\ncyan was not found in colors" << endl;
    }
}