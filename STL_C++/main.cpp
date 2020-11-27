#include<iostream>
#include<iomanip>
#include<cstdlib> //contains function prototype for rand
using namespace std;

int main() {
    unsigned int seed{0};

    cout << "Enter seed ";
    cin >> seed;

    //seed the random number generator
    srand(seed);

    for(unsigned int roll{1}; roll <= 10; ++roll) {
        cout << setw(10) << (1+rand()%6);
        if(roll%5==0) cout << endl;
    }
}