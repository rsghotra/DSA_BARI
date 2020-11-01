#include<iostream>
using namespace std;

/*
Tridiagonal Matrix: A square matrix whose Main Diagonal; Lower and Upper Diagonal are non and all other are zero.
Definition: M[i][j] != 0 if |i-j| <= 1;
Number of Elements Need to Store: 3N-2
Mapping:
    - Must handle all three diagonals separately:
    if(i-j == 1)
    if(i-j == 0)
    if(i-j == -1)

*/


struct Tridiagonal {
    int N;
    int* A;
};

void set_element(Tridiagonal* td, int i, int j, int k) {
    if((i-j)==1) {
        //Lower Diagonal Detected
        td->A[j-1] = k;
    } else if((i-j)==0) {
        //Diagonal Element Detected
        td->A[td->N-1 + (j-1)] = k;
    } else if((i-j)==-1){
        //Upper Diagonal Element Detected
        td->A[(td->N-1)+(td->N)+(i-1)] = k;
    }
}

int get_element(Tridiagonal td, int i, int j) {

    if((i-j) == 1) {
        return td.A[j-1];
    } else if((i-j) == 0) {
        return td.A[td.N-1 + (j-1)];
    } else if((i-j) == -1) {
        return td.A[td.N-1 + td.N + (i-1)];
    } else {
        return 0;
    }
}

void display(Tridiagonal td) {
    int i, j;
    cout << "Tridiagonal Matrix: " << endl;
    for(i=1;i<=td.N;i++) {
        for(j=1;j<=td.N;j++) {
            cout << get_element(td, i, j) << " ";
        }
        cout << endl;
    }
}

void create(Tridiagonal* td) {
    cout << "Enter dimensions of a tridigonal matrix: ";
    cin >> td->N;
    //create array matrix of size 3N-2
    td->A = new int[3*td->N - 2]();
    cout << "Enter Matrix and the program will set it as Tridiagonal Matrix." << endl;
    int k;
    for(int i=1;i<=td->N;i++) {
        for(int j=1;j<=td->N;j++) {
            cin >> k;
            set_element(td,i,j,k);
        }
    }
}


int main() {
    Tridiagonal td;
    //Remember user will give input starting from index1
    create(&td);
    display(td);
}