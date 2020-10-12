#include <iostream>

using namespace std;

double e_horner_iter(int x, int n) {
    double sum = 1;
    for(;n>0;n--) {
        //note - not =+ only =
        sum = 1 + (x*1.0/n)*sum;
    }
    return sum;
}

double e_horner_recur(int x, int n) {
    double static sum = 1;
    if(n == 0) return sum;
    sum = 1 + (x*1.0/n)*sum;
    //Tail recursion can easily be convertied to loops
    return e_horner_recur(x, n-1);
}

int main() {
    cout << "The exponent function(iterative) " << e_horner_iter(5, 10) << endl;
    cout << "The exponent function(iterative) " << e_horner_recur(5, 10) << endl;
    return 0;
}