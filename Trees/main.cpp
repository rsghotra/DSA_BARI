#include<iostream>

using namespace std;

int main() {
    char* input = new char[20];
    std::cout<<"Enter your Name"<<endl;
    cin.getline(input, 20);
    std::cout<<"Your name is: "<<input<<endl;
    return 0;
}
