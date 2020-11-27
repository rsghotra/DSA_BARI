#include<iostream>
#include<iomanip>
#include<ctime>
#include<random>
#include<array>
using namespace std;

int main() {
    //create random engine and seed it with time
    default_random_engine engine{static_cast<unsigned int>(time(0))};
    uniform_int_distribution<unsigned int> randomInt{1,6};

    const size_t arraySize = 7;
    array<unsigned int, arraySize> frequency{0}; //initialized to zero

    for(size_t roll{1}; roll <= 60'000'000; ++roll) {
        frequency[randomInt(engine)] += 1;
    }

    cout << "Face" << setw(13) << "Frequency" << endl;

    for(size_t face{1}; face < frequency.size(); ++face) {
        cout << setw(4) << face << setw(13) << frequency[face] << endl;
    }
}