#include<iostream>
#include<iomanip>
#include<random> //contain number generation engine
#include<ctime> //to seed the number generator
using namespace std;

int main() {
    //it is an object which need unsigned_int type seed value
    default_random_engine engine{static_cast<unsigned int>(time(0))};
    //for die problem we would like to have normal distribution
    //scoped and scaled
    uniform_int_distribution<unsigned int> randomInt{1,6};
    return 0;
}