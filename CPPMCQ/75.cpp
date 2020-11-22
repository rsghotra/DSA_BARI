#include <iostream>
#include <fstream>
using namespace std;

/*
    Concepts: 
        - Comma Separation Instruction. Ever comma is one single instruction;
        - Paranthesis Close Bracket: Group all the instrcutions together


*/
int main() {
    int v1, v2;
    //v1 = 1; v1 will have only 1;
    v1 = 1,2,3,4;
    //v2 will have only 4. Comma is evaluated left to right and last instruction is sent
    //v2 will have last value of instruction
    v2 = (1,2,3,4);
    cout << v1 << " " << v2 << endl;
    return 0;
}

//A. Compilation Error

//B. RTE

//C. Garbage Value

//D. 10