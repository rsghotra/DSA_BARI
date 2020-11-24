#include<iostream>
#define SIZE 10
#define PRIME 7
using namespace std;

/*
    Closed Hashing - Double Hashing: Collision Resolution Technique - Implemented Using Array
        Key Points: 
            - Resolves Collision Problem: As it consider PRIME NUMBER
            - Space Efficient
            - Resolves Primary Clustering Problem
            - Utilized two HASH FUNCTIONS
            H1(x) = x%size;
            H2(x) = R - size%R;
            H3'(x) = (H1(x) + i*H2(x))%size; 
            Benefits:
                1. Load Factor, Lambda <=1
                2. Resolve Collision & Primary Clustering
*/

//H(x) = x%size
int Hash(int key) {
    return key%SIZE;
}

int PrimeHash(int key) {
    return PRIME - (key%PRIME); 
}

//you will only call linear probling if Modulus Hash Function Fails
int DoubleHash(int HT[], int key) {
    int index = Hash(key);
    int i = 0;
    do {
        if(HT[(index + i*PrimeHash(key))%SIZE]==0) {
            return ((index + i*PrimeHash(key))%SIZE);
        }
        i++;
    } while((index + i*PrimeHash(key))%SIZE !=index); //HT is full
    return -1;
}

int Search(int HT[], int key) {
    int index = Hash(key);
    int i = 0;
    do {
        if(HT[(index + i*PrimeHash(key))%SIZE] == key) {
            return ((index + i*PrimeHash(key))%SIZE);
        }
        i++;
    } while((index + i*PrimeHash(key))%SIZE != index);
    return -1;
}

void Insert(int HT[], int key) {
    //first try for regular insert
    int index = Hash(key);
    if(HT[index] != 0) {
        //call for linear probing
        index = DoubleHash(HT, key);
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
    Insert(HT, 5);
    PrintHash(HT);
    cout << "Key found at " << Search(HT, 35) << endl;
    cout << "Key found at " << Search(HT, 30) << endl;
    cout << "Key found at " << Search(HT, 55) << endl;
}