#include <iostream>

using namespace std;

void arrSelectSort(int* [], int);
void showArray(const int arr[], int size);
void showArrPtr(int* arr[], int size);


int main() {
    const int NUM_DONATIONS=15;
    int donations[NUM_DONATIONS] = {5,100,5,25,10,5,25,5,5,100,10,15,10,5,10};
    int* arrPtr[NUM_DONATIONS];
    for(int i=0;i<NUM_DONATIONS;i++) {
        arrPtr[i]=&donations[i];
    }
    cout << ">======> Printing Donations Array: " << endl;
    showArray(donations, NUM_DONATIONS);
    cout << ">======> Printing Pointer Array: " << endl;
    showArrPtr(arrPtr, NUM_DONATIONS);
    arrSelectSort(arrPtr, NUM_DONATIONS);
    cout << ">======> Printing Pointer Array: " << endl;
    showArrPtr(arrPtr, NUM_DONATIONS);

    return 0;
}

void arrSelectSort(int* arr[], int size) {
    int minIndex;
    int *key;
    for(int i = 0; i < size-1; i++) {
        key = arr[i];
        minIndex=i;
        for(int j=i+1;j<size;j++) {
            if(*key > *(arr[j])) {
                key = arr[j];
                minIndex=j;
            }
        }
        arr[minIndex]=arr[i];
        arr[i]=key;
    }
}

void showArray(const int arr[], int size) {
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void showArrPtr(int* arr[], int size) {
    for(int i=0;i<size;i++) {
        cout << *(arr[i]) << " ";
    }
    cout << endl;
}