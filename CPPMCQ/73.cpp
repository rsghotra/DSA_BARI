#include <iostream>
#include <fstream>
using namespace std;

/*
    Concepts: File Streaming - End of File function
*/

int main() {
    char buf[100];
    ifstream myfile("C:\\gitP\\AbdulBari\\CPPMCQ\\sample.txt");
    while(!myfile.eof()) {
        myfile.getline(buf, 50);
        cout << buf << endl;
    }
    return 0;
}

//A. Compilation Error

//B. While it is not end of file, output file line by line

//C. Will search of end of line if it exists

//D. While it is end of file print  last line