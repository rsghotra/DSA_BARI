#include <iostream>

/*
Sum of first n natural numbers using:

1. formula
2. recursion
3. iterative
*/

using namespace std;

int sum_formula(int n) {
    return (n * (n+1))/2;
}

int sum_iterative(int n) {
    int i;
    int sum=0;
    for(i=1;i<=n;i++) {
        sum += i;
    }
    return sum;
}

int sum_recursive(int n) {
    if(n==0) {
        return 0;
    } else {
        return sum_recursive(n-1) + n;
    }
}

int main() {
    int number = 0;
    do {
        cout << "Please enter the number for which you'd like the sum?" << endl;
        cin >> number;
    }while(number < 0);
    cout << "Sum of first n natural numbers using formula(T(n)=O(1);S(n)=O(1)): " << sum_formula(number) << endl;
    cout << "Sum of first n natural numbers using iteration(T(n)=O(n);S(n)=O(1)): " << sum_iterative(number) << endl;
    cout << "Sum of first n natural numbers using recursion(T(n)=O(n);S(n)=O(n)): " << sum_recursive(number) << endl;
    return 0;
}