//https://brilliant.org/wiki/pascals-triangle/#:~:text=Pascal's%20triangle%20is%20a%20triangular,Pascal%20(1623%20%2D%201662).

/*
Implementation of nCr i.e. Selction Formula
Can be implemented usng two methods:

1. Using formula - O(n)
2. Using Pascal's Triange - O(n)
*/

#include <iostream>

using namespace std;

//helper
int fact(int n) {
    if(n == 0) return 1;
    return fact(n-1) * n;
}

//direct formula
int nCr(int n, int r) {
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n-r);
    return num/den;
}



int nCr_pascal(int n, int r) {
    if( r == 0 || r == n) {
        return 1;
    }
    return nCr_pascal(n-1, r-1) + nCr_pascal(n-1, r);
}


int main() {
    int n, r;
    cout << "Choose n in nCr: " << endl;
    cin >> n;
    cout << "Choose r in nCr: " << endl;
    cin >> r;
    cout << "Total number of way to select(using formula): " << nCr(n,r);
    cout << "\nTotal number of ways to select(using Pascal Triangle): "<< nCr_pascal(n, r) << endl;
    return 0;
}