#include<iostream>
#include<time.h>
#include<cstdlib>
#include<ctime>
using namespace std;

/*
ALL MATRIX CREATED FROM THIS PROGRAM WILL BE NxN or Square Marix
Assuming Matrices starts from INDEX 1.
NxN=[1,2,3,4,5],[1,2,3,4,5]
Array it will be stored from  0 to 4.
What does it mean is that when user will supply row and coloum starting from 1-n.
We need to process it accrodingly.

*/

struct Matrix {
    int* A;
    int n;
};

/*
*************CREATE A DIAGONAL MATRIX**********
*/
void create_diagonal(Matrix* m, int n) {
    //creating struct now.
    m->n=n;
    m->A=new int[m->n]();
}

/*
*************GET ELEMENT FROM A DIAGONAL MATRIX**********
*/
int get_diagonal(Matrix m, int i, int j) {
    //remember user will send index from 1,1
    if(i==j) {
        return m.A[i-1];
    } else {
        return 0;
    }
}

/*
*************SETS ELEMENT IN A DIAGONAL MATRIX**********
*/
void set_diagonal(Matrix* m, int i, int j, int x) {
    if(i==j) {
        m->A[i-1]=x;
    } else {
        m->A[i-1]=0;
    }
}

/*
*************PRINTS ELEMENT IN A DIAGONAL MATRIX**********
*/
void display_diagonal(Matrix m) {
    //Remember it is saved as an 1D array
    for(int i=0;i<m.n;i++) {
        for(int j=0;j<m.n;j++) {
            if(i==j) {
                cout << m.A[i] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}



void _diagonal_matrix() {
    string theoretical = "Definition: Matrices which are NxN dimensions and in which only diagnoal elements i.e. where r=c is non-zero. All other elements are 0.";
    string mathematical = "Mathematical => M[i][j]=0 if i != j";
    int choice=0; int done = 0;
    int n; int r, c;
    int key;
    Matrix M;
    while(done != 1) {
        do {
        cout << "1. Creator: Create a Diagonal Matrix of asked dimension filled with numbers only at diagonal position as per definition of the matrix." << endl;
        cout << "2. Setter: Sets element in the matrix at given index." << endl;
        cout << "3. Getter: Fetches an element from asked indicies." << endl;
        cout << "4. Display: Prints a diagonal matrix." << endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
        } while(choice != -1 && !(choice >= 1 && choice <=4));

        switch(choice) {
            case 1:
                do {
                    cout << "Please enter 1 dimension of the Square-Diagonal Matrix." << endl;
                    cin >> n;
                } while(n <= 0);
                create_diagonal(&M, n);
                break;
            case 2:
                cout << "==>Set Opertaion."<<endl;
                do {
                    cout << "Row Index(1-" << n << "): ";
                    cin >> r;
                } while( r<=0 && r>n);
                do {
                    cout << "Coloum Index(1-" << n << "): ";
                    cin >> c;
                } while( c<=0 && c>n);
                cout << "Enter the value: ";
                cin >> key;
                set_diagonal(&M, r, c, key);
                break;
            case 3:
                cout << "==>Get Opertaion."<<endl;
                do {
                    cout << "Row Index(1-" << n << "): ";
                    cin >> r;
                } while( r<=0 && r>n);
                do {
                    cout << "Coloum Index(1-" << n << "): ";
                    cin >> c;
                } while( c<=0 && c>n);
                cout << "Value: " << get_diagonal(M, r, c) << endl;
                break;
            case 4:
                cout << "Value of M before display: " << M.n << endl;
                display_diagonal(M);
                break;
        }
        if(choice==-1) done=1;
    }
}

/*
*************Lower Triangular Matrix**********
*/

void create_lower_triangular(Matrix* M) {

}

void set_lower_triangular(Matrix* M) {
    
}

void get_lower_triangular(Matrix M) {
    
}

void display_lower_triangular(Matrix M) {
    
}

void _lower_triangular_matrix() {
    cout << "Welcome to Lower triangular marix. What would you like to do?" << endl;
    Matrix M;

    int choice=0, done=0;
    while(done!=1) {
        do {
            cout << "1. Creator: Create a Lower Triangular Matrix of asked dimension filled initialized to zero." << endl;
            cout << "2. Setter: Sets element in the matrix at given index." << endl;
            cout << "3. Getter: Fetches an element from asked indicies." << endl;
            cout << "4. Display: Prints a diagonal matrix." << endl;
            cout << "-1. Exit." << endl;
            cin >> choice;
        } while(choice != -1 && !(choice >= 1 && choice <=4));
        switch(choice) {
            case 1:
                create_lower_triangular(&M);
                break;
            case 2:
                set_lower_triangular(&M);
                break;
            case 3:
                get_lower_triangular(M);
                break;
            case 4:
                display_lower_triangular(M);
                break;
        }
        if(choice==-1) done=1;
    }

    delete[] M.A;
}

int main() {
    int choice=0;
    do {
        cout<<"Welcome to the Fox world of Matrix. Every option displays its own options.Choose your path wisely!" << endl;
        cout << "1. Diagonal Matrix." << endl;
        cout << "2. Lower Triangular Matrix."<<endl;
        cout << "3. Upper Triangular Matrix."<<endl;
        cout << "4. Symmetric Matrix."<<endl;
        cout << "5. Tridiagonal Matrix."<<endl;
        cout << "6. Band Matrix."<<endl;
        cout << "7. Toeplitz Matrix."<<endl;
        cout << "8. Sparse Matrix."<<endl;
        cout << "-1. To Exit." << endl;
        cin >> choice;
    } while(choice != -1 && !(choice >= 1 && choice <=18));

    switch(choice) {
        case 1:
            _diagonal_matrix();
            break;
        case 2:
            _lower_triangular_matrix();
        //     break;
        // case 3:
        //     _upper_triangular_matrix();
        //     break;
        // case 4:
        //     _symmetric_matrix();
        //     break;
        // case 5:
        //     _tri_diagonal_matrix();
        //     break;
        // case 6:
        //     _band_matrix();
        //     break;
        // case 7:
        //     _toeplitz_matrix();
        //     break;
        // case 8:
        //     _sparse_matrix();
        //     break;
        case -1:
            cout << "Thank You for Visiting the World of String! :)" << endl; 
    }

}