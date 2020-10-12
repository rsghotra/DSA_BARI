#include <iostream>

using namespace std;

int main()
{
    //static array
    int A[5] = {2,4,6,8,10};
    //static array access
    int i;
    cout << A[1] << endl;
    int *P;
    P = new int[5];
    P[0]=3;
    P[1]=5;
    P[2]=7;
    P[3]=9;
    P[4]=11;
    for(i=0;i<5;i++) {
        cout << "Static array element: A["<< i << "]: " << A[i] << endl;
        cout << "Dynamic array element:P["<< i << "]: " << P[i] << endl;
    }
    return 0;
}