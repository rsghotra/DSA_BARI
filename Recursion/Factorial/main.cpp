#include <iostream>

using namespace std;

int fact_iter(int n);
int fact_recr(int n);

int main() {
    int number;
    cout << "Please enter a number to find its factorial: ";
    cin >> number;
    cout << "Product of first n natural numbers using iteration(T(n)=O(n);S(n)=O(1))="<<fact_iter(number)<<endl;
    cout<<"Product of first n natural numbers using recursion(T(n)=O(n);S(n)=O(n)="<<fact_recr(number)<<endl;
    return 0;
}

int fact_iter(int n) {
    int factorial=1;
    int i;
    for(i=1;i<=n;i++) {
        factorial = factorial * i;
    }
    return factorial;
}

int fact_recr(int n) {
    if(n==0) {
        return 1; //Since it is a multiplicative operation therefore - base case has to be 1
    } else {
        return fact_recr(n-1)*n;
    }
}