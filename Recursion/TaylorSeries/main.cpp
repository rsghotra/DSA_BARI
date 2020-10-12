#include <iostream>

using namespace std;

/*
Implementing one of the nasty function of the world 'exponent' using Taylor series.
- Taylor series consists of:
    1. Summation
    2. Power
    3. Factorial
- Since, denominator consists of the most powerful function in the world which factorial hence the
series definitely converges sooner than you think.
- Second, Taylor series is pretty multiplication intensive and the series converges as well. Hence, improvement
is definitely possible.
- Third, then came the Horner's rule who reduces the number of multiplcations need to be done by
taking COMMONS
- int e(int x, int n) = where x = power of the exponent whose value we want to find.
- int n = Number of terms of Taylor series need to be used to calculated the value. 
- More the number of terms n - more accurate will be the result.
*/

double e(int x, int n) {
    static double p=1;
    static double f=1;
    double r;
    if(n==0) {
        return 1;
    } else {
        r=e(x, n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}

int main() {
    int x = 3;
    int n = 10;
    cout << "The value of e^" << x << " calculated with " << n << " terms of Taylor series: " << e(x, n) << endl;
    return 0;
}