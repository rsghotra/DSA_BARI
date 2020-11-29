#include<iostream>
#include<iomanip>
#include<vector>
#include<stdexcept>
using namespace std;

void inputVector(vector<int>& vect) {
    for(int& item: vect) {
        cin >> item;
    }
}

//output vector contents
void outputVector(const vector<int>& vect) {
    for(int item: vect) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    vector<int>vect{7}; //this won't create a vector of size 7 but will create vector of size 1 with element 7
    vector<int> vect1(7);
    vector<int> vect2(10);

    cout <<"Size of vect1"<<setw(2)<<vect1.size()
        <<"\nvector after initialization:";
    outputVector(vect1);

    cout <<"Size of vect2"<<setw(2)<<vect2.size()
        <<"\nvector after initialization:";
    outputVector(vect2);

    cout << "\nEnter 17 integers:"<< endl;
    inputVector(vect1);
    inputVector(vect2);

    cout<<"\nAfter input, the vectors contain:\n"
        <<"vect1: ";
    outputVector(vect1);
    cout <<"vect2: ";
    outputVector(vect2);

    cout <<"\nEvaluating: vect1 != vect2" << endl;
    if(vect1 != vect2) {
        cout <<"vect1 and vect2 are not equal" << endl;
    }
    //copy constructor
    //create new vect3 and initialize it using vect1 and then print its content and size
    vector<int> vect3{vect1}; //copy constructor

    cout <<"\nSize of vect3"<<setw(2)<<vect3.size()
        <<"\nvector after initialization: ";
    outputVector(vect3);


    cout <<"\nAssigning vect2 to vect1: " << endl;
    vect1=vect2;

    cout<<"vect1: ";
    outputVector(vect1);
    cout<<"vect2: ";
    outputVector(vect2);

    cout<<"\nEvaluating: vect1 == vect2" << endl;

    if(vect1==vect2) {
        cout<<"vect1 and vect2 are equal"<<endl;
    }
    //using square bracket as rvalue
    cout <<"\nvect1[5] is " << vect1[5];
    //use square bracket as lvalue
    cout <<"\n\nAssigning 1000 to vect1[5]" << endl;
    vect1[5] = 1000;
    cout <<"vect1: ";
    outputVector(vect1);

    //attempting to use out of range subscript
    try {
        cout <<"\nAttempt to display vect1.at(15)" << endl;
        cout << vect1.at(15) << endl; //ERROR out of range
    }
    catch(out_of_range& ex) {
        cerr <<"An exception occurred: " << ex.what() << endl;
    }

    //changing the size of a vector
    cout <<"\nCurrent vect3 size is " << vect3.size() << endl;
    vect3.push_back(1000);// add 100 to end of the vector
    cout <<"\nNew vect3 size is " << vect3.size() << endl;
    cout <<"\nvect3 now contains: ";
    outputVector(vect3);
}