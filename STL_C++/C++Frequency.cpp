#include<iostream>
#include<iomanip>
#include<cstdlib> //contains function prototype for rand
using namespace std;

int main() {
    unsigned int frequency1{0};
    unsigned int frequency2{0};
    unsigned int frequency3{0};
    unsigned int frequency4{0};
    unsigned int frequency5{0};
    unsigned int frequency6{0};
    
    unsigned int face;
    cout << "RAND_MAX" << setw(10) << RAND_MAX << endl;
    for(unsigned int roll{1}; roll <= 60'000'000; ++roll) {
            face = 1 + rand()%6;
            switch(face) {
            case 1:
                ++frequency1;
                break;
            case 2:
                ++frequency2;
                break;
            case 3:
                ++frequency3;
                break;
            case 4:
                ++frequency4;
                break;
            case 5:
                ++frequency5;
                break;
            case 6:
                ++frequency6;
                break;
            default:
                cout << "Program should never reach here" << endl;
        }
    }
    cout << "Face" << setw(13) << "Frequency" << endl;
    cout << "  1" << setw(13) <<  frequency1
        << "\n  2" << setw(13) << frequency2
        << "\n  3" << setw(13) << frequency3
        << "\n  4" << setw(13) << frequency4
        << "\n  5" << setw(13) << frequency5
        << "\n  6" << setw(13) << frequency6 << endl;
}