#include <iostream>

using namespace std;

/*
Efficient power function
*/

int power(int, int);
int power_efficient(int, int);

int power(int m, int n) {
    if(n==0) {
        //since multiplicative operation therefore 1.
        return 1;
    } else {
        return power(m, n-1) * m;
    }
}

int power_efficient(int m, int n) {
    if(n==0) {
        return 1; 
    }
    if(n%2==0) {
        return power_efficient(m*m, n/2);
    } else {
        return m * power_efficient(m*m, (n-1)/2);
    }
}

int main() {
    int m, n;
    cout << "Please enter Begger: " << endl;
    cin >> m;
    cout << "Please enter Biscuit: " << endl;
    cin >> n;
    cout << "Simple Power Recursion: " << power(m, n) << endl;
    cout << "Efficient Power Recursion: " << power_efficient(m, n) << endl;
    return 0;
}