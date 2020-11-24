#include<iostream>
using namespace std;

/*
    ==> NEED NOT TO WORRY ABOUT IF THE ELEMENT COULD BE INSERTED OR NOT AS HASH TABLE SIZE IS EQUAL TO INPUT SIZE
    Closed Hashing - Quadratic Probing: Collision Resolution Technique - Implemented Using Array
        Key Points: H'(x) = (H(x) + i*i)%size; where H(x) = x%size; i = 0,1,2,3
            Benefits:
                1. Load Factor, Lambda <=1
                2. Resolve Collision & Primary Clustering
*/

const int SIZE = 10;

//H(x) = x%size
int Hash(int key) {
    return key%SIZE;
}

//you will only call linear probling if Modulus Hash Function Fails
int QuadraticProbe(int HT[], int key) {
    int index = Hash(key);
    int i = 0;
    do {
        if(HT[(index + i*i)%SIZE]==0) {
            return ((index+i*i)%SIZE);
        }
        i++;
    } while((index + i*i)%SIZE !=index); //HT is full
    return -1;
}

int Search(int HT[], int key) {
    int index = Hash(key);
    int i = 0;
    do {
        if(HT[(index+i*i)%SIZE] == key) {
            return ((index+i*i)%SIZE);
        }
        i++;
    } while((index+i*i)%SIZE != index);
    return -1;
}

void Insert(int HT[], int key) {
    //first try for regular insert
    int index = Hash(key);
    if(HT[index] != 0) {
        //call for linear probing
        index = QuadraticProbe(HT, key);
    }
    if( index == -1) {
            cout << "Hash Table is Full." << endl;
    } else {
        HT[index]= key;
    }
}

void PrintHash(int HT[]) {
    for(int i = 0; i < SIZE; i++) {
        cout << HT[i] << " ";
    }
    cout << endl;
}

int main() {
    //must initialized with zero
    int HT[SIZE] = {0};
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 55);
    Insert(HT, 39);
    Insert(HT, 41);
    PrintHash(HT);
    cout << "Key found at " << Search(HT, 35) << endl;
    cout << "Key found at " << Search(HT, 30) << endl;
    cout << "Key found at " << Search(HT, 55) << endl;
}