/*
Symmetry Matrix: M[i][j] = M[j][i]

*/
#include<iostream>
using namespace std;
class Symmetry {
    private:
        int N;
        int* A;
    public:
        Symmetry(int n) {
            this->N = n;
            this->A = new int[this->N*(this->N+1)/2];
        }
        void create();
        void display();
        int get_element(int, int);
        void set_element(int, int, int);
};

void Symmetry::display() {
    cout << "Symmetric Matrix: " << endl;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << get_element(i,j) << " ";
        }
        cout << endl;
    }
}

void Symmetry::set_element(int i, int j, int k) {
    //Lower Triangular Matrix Area - I am going to store it - row - major
    if(i >= j) {
        A[i*(i-1)/2 + (j-1)] = k;
    }
}

int Symmetry::get_element(int i, int j) {
    if(i >= j) {
        return A[i*(i-1)/2 + (j-1)];
    } else {
        //when asked to return element from upper triangle which is just mirror of this.
        return A[j*(j-1)/2 + (i-1)];
    }
}

void Symmetry::create() {
    int k;
    cout << "Enter Matrix: "<< endl;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> k;
            set_element(i,j,k);
        }
    }
}

int main() {
    int n;
    cout << "Welcome to Symmetry Matrix!" << endl;
    cout << "Enter Dimensions: ";
    cin >> n;
    Symmetry sym(n);
    sym.create();
    sym.display();
}