#include <iostream>

using namespace std;

void fun(int);

//Head Recursion i.e; recursive call then operations.
void fun1(int n) {
    if(n>0) {
        fun(n-1);
        cout << n << endl;
    }
}
//Tail Recursion i.e; operation then recursve call.
void fun2(int n) {
    if(n>0) {
        cout << n << endl;
        fun(n-1);
    }
}

int main() {
    int x = 3;
    fun1(x);
    //fun2(x);
    return 0;
}