#include<iostream>

using namespace std;

class LowerTri {
    private:
        int N;
        int* A;
    public:
        LowerTri(int n) {
            this->N=n;
            this->A= new int[N*(N+1)/2]();
        }
        ~LowerTri() {
            delete[] A;
        }
        void set_row_major(int i, int j, int k);
        int get_row_major(int i, int j);
        void set_col_major(int i, int j, int k);
        int get_col_major(int i, int j);
        void display(bool row=true);
};

void LowerTri::set_row_major(int i, int j, int k) {
    if(i>=j) {
        A[i*(i-1)/2 + j-1] = k;
    }
}

int LowerTri::get_row_major(int i, int j) {
    if(i>=j) {
        return A[i*(i-1)/2 + j-1];
    } else {
        return 0;
    }
}

void LowerTri::set_col_major(int i, int j, int k) {
    if(i>=j) {
        A[N*(j-1) - (j-2)*(j-1)/2 + i-j] = k;
    }
}

int LowerTri::get_col_major(int i, int j) {
    if(i>=j) {
        return A[N*(j-1) - (j-2)*(j-1)/2 + i-j];
    } else {
        return 0;
    }
}

void LowerTri::display(bool row) {
    cout << "Displaying Matrix now.."<<endl;
    for(int i=1;i<=N;i++) {
        //checkout index starting from 1
        for(int j=1;j<=N;j++) {
            if(i>=j){
                if(row) {
                    cout << get_row_major(i,j) << " ";
                }
                else {
                    cout << get_col_major(i,j) << " ";
                }
            }
            else {cout << 0 << " ";}
        }
        cout << endl;
    }
}

int main() {
    int n,x;
    cout << "Enter dimension: ";
    cin >> n;
    LowerTri lt_row(n);
    //REMEMBER USER WILL SUPPLY VALUES STARTING FROM 1-N
    cout << "Enter elements: " << endl;
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n;j++) {
            cin>>x;
            lt_row.set_row_major(i,j,x);
            //lt_row.set_col_major(i,j,x);
        }
    }
    lt_row.display();
    return 0;
}