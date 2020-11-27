#include<iostream>
#include<iomanip>
#include<ctime>
#include<random>
using namespace std;

int main() {
    //engine generates psuedo random number
    default_random_engine engine{static_cast<unsigned int>(time(0))};
    //psuedo random number is converted to proper type and range
    uniform_int_distribution<unsigned int> randomInt{1,6};

    //loop 10 times
    for(unsigned int i{1}; i <= 10; i++) {
        cout << setw(10) << randomInt(engine);
        if(i%5 == 0) cout << endl;
    }
    return 0;
}