#include<iostream>
#include<iomanip>
#include<array>
using namespace std;

int main() {
    array<int,5>items{1,2,3,4,5};

    cout<<"items before mofication" << endl;

    for(int item: items) {
        cout << item << " ";
    }
    cout << endl;

    
    //item represent a value - not a subscript
    for(int& item: items) {
        item *= 2;
    }


    cout<<"items after modification" << endl;

    for(int item: items) {
        cout << item << " ";
    }
    cout << endl;
}