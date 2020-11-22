#include <iostream>
#include <fstream>
using namespace std;

/*
    Concepts: Switch - Skipping creating and initialization is not allowed in switch.
        EVERYTHING IN SWITCH BLOCK IS IN ONE SCOPR
        case 1:
            int x = 10; - NOT ALLOWED
        case 1:
            int x;      - ALLOWED
        OR
            DO IT LIKE THIS
                case 1:{ ==>NOW IT WILL BE SCOPED; ON OTHERHAND INITIALIZATION STATEMENT COULD BE SKIPPED
                int x = 10;
                cout << x << endl;
                break;
            }

*/
int main() {
    int i = 1;
    switch(i) {
        //watch out
        case 1: {
            int x = 10;
            cout << x << endl;
            break;
        }
        default:
            cout << "default" << endl;
            break;
    }
    return 0;
}

//A. Compilation Error

//B. RTE

//C. Garbage Value

//D. 10