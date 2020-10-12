#include <iostream>

/*
- TOH is a time consuming function
- O(2^n)
*/

using namespace std;

void TOH(int n, int a, int b, int c) {
    if(n>0) {
        TOH(n-1, a, c, b);
        cout << "Moving a disk from Tower " << a << " to Tower " << c << " via " << b << endl;
        TOH(n-1, b, a, c);
    }
}

int main() {
    TOH(3, 1, 2, 3);
    return 0;
}