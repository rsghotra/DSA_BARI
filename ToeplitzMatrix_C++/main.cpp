#include<iostream>
using namespace std;

class Toeplitz {
    private:
        int N;
        int* A;
    public:
        Toeplitz(int N) {
            this->N = N;
            this->A = new int[2*N-1];
        }
        ~Toeplitz() {
            delete [] A;
        }
        void set_element(int i, int j, int k);
        int  get_element(int i, int j);
        void display();
};