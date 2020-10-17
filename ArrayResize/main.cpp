#include <iostream>

using namespace std;

int main() {
    int *P = new int[5];
    P[0]=3;
    P[1]=5;
    P[2]=7;
    P[3]=9;
    P[4]=11;
    int *Q=new int[10];

    //copying values over
    for(int i=0; i<5; i++) {
        Q[i]=P[i];
    }
    delete [] P;
    P=Q;
    Q=NULL;
    for(int j=0;j<5;j++) {
        cout << "Big array element P[" <<j<<"]: " << P[j] << endl; 
    }
    return 0;
}