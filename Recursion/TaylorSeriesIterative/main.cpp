#include <iostream>

using namespace std;

double e_iter(int x, int n) {
    //some values to hold the results.
    double sum=1;
    double num=1;
    double deno=1;
    //num/deno will give you the first term
    for(int i=1;i<=n;i++) {
        num = num*x;
        deno = deno*i;
        sum+= num/deno;
    }
    return sum;
}

int main() {
    cout << "The exponent function(iterative) " << e_iter(2, 10) << endl;
    return 0;
}