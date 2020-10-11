#include <iostream>
using namespace std;

/*
Fibonacci series implementation in computers.
Three ways to implememnt:

1. Iterative: T(n) = O(n);
2. Extensive Recusrive: T(n) = O(2^n)
3. Memoization Recursive: T(n) = O(n)
*/

int fib_iter(int n);
int fib_recur(int n);
int fib_memo(int n);
static int arr[100];

int fib_iter(int n) {
    //handling edge case first;
    if(n<=1) {
        return n;
    }
    int sum = 0;
    int t0 = 0;
    int t1 = 1;
    for(int i=2; i<=n;i++) {
        sum=t0+t1;
        t0=t1;
        t1=sum;
    }
    return sum;
}

int fib_recur(int n) {
    if(n<=1) return n;
    return fib_recur(n-2)+fib_recur(n-1);
}

int fib_memo(int n) {
    //static array is already declared and filled with -1;
    if(n<=1) {
        arr[n] = n;
        return arr[n];
    }
    if(arr[n-2] == -1) {
        arr[n-2] = fib_memo(n-2);
    }
    if(arr[n-1] == -1) {
        arr[n-1] = fib_memo(n-1);
    }
    arr[n] = arr[n-2] + arr[n-1];
    return arr[n];
}

int main() {
    int n;
    //For memoization
    for(int i=0;i<100;i++) arr[i] = -1;
    cout << "Please enter the number until which you'd like to see fibonacci series: " << endl;
    cin >> n;

    cout << "Answer using Iterative solution ==>T(n):O(n); Fib(" << n << ")=" << fib_iter(n) << endl;
    cout << "Answer using Memoization-Recursive solution ==>T(n):O(n); Fib(" << n << ")=" << fib_memo(n) << endl;
    cout << "Answer using Extensive Recursion solution ==>T(n):O(2^n); Fib(" << n << ")=" << fib_recur(n) << endl;
    return 0;
}