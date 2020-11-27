#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

int main () {
    unsigned int seed = static_cast<unsigned int>(time(0));
    srand(seed);
    for(unsigned int roll{1}; roll <=10; ++roll) {   
        cout << setw(10) << (1+rand()%6);
        if(roll%5 == 0) cout << endl; 
    }
    return 0;
}