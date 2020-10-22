#include <iostream>

using namespace std;

/*
Checking if given array is already sorted
*/

struct Array {
    int A[10];
    int length;
    int size;
};

void Display(Array a) {
    //as it is passed by value therefore - hence it is an object
    for(int i=0;i<a.length;i++) {
        cout<< a.A[i] << " ";
    }
    cout<<endl;
}

bool isSorted(Array a) {
    // ||==> Watchout; We are traversing until second last element due to forward copy operations.
    // ||==> Watchout: We start from the beginning
    for(int i=0;i<a.length-1;i++)  {
        if(a.A[i]>a.A[i+1]) return false;
    }
    return true;
}

int main() {
    //initialized
    Array arr = {{2,3,5,7,9}, 5, 10};
    cout<<">==>Displaying array: "<<endl;
    Display(arr);
    if(isSorted(arr)) {
        cout << ">==>isSorted():The array is Sorted."<<endl;
    } else {
        cout << ">==>isSorted():Array Not Sorted!"<<endl;
    }
    return 0;   
}