#include<iostream>
using namespace std;

/*
Toeplitz Matrix: When all diagonals of the matrix are same. M[i][j] == M[i-1][j-1] then it is Toelplitz matrix
1 2 3
4 1 2
5 4 1

- Number of Elements Required: Only Need to save first row + first coloum - first element = n+n-1 = 2N-1
*/
class Toeplitz {
    private:
        int N;
        int* A;
    public:
        Toeplitz(int N) {
            this->N = N;
            this->A = new int[2*N-1]();
        }
        ~Toeplitz() {
            delete [] A;
        }
        void set_element(int i, int j, int k);
        int  get_element(int i, int j);
        void display();
        void create();
};

void Toeplitz::create() {
    cout << "Enter Matrix: " << endl;
    int k;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> k;
            set_element(i,j,k);
        }
    }
}

void Toeplitz::set_element(int i, int j, int k) {
    // can been seen as upper triangular + lower triangular - diagonal
    //upper triangular part
    if(i <= j) {
        A[j - i] = k;
    } else {
        //lower triangular part
        A[N + i - j - 1] = k;
    }
}

int Toeplitz::get_element(int i, int j) {
    if(i<=j) {
        return A[j-i];
    } else {
        return A[N + i-j-1];
    }
}

void Toeplitz::display() {
    cout << ">==>Toeplitiz Matrix: " << endl;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << get_element(i,j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter dimensions: ";
    cin >> n;
    Toeplitz tp(n);
    tp.create();
    tp.display();
}