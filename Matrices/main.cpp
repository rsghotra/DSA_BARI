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

void set_lower_tri(Matrix* M, int i, int j, int k, bool row);
void set_upper_tri(Matrix* M, int i, int j, int k, bool row);
int get_upper_tri(const Matrix* M, int i, int j, bool row);
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

void create_lower_tri(Matrix* M, bool row) {
    int n;
    cout << "Enter dimension:: ";
    cin >> n;
    M->n=n;
    /*
        Lower Triangular Matrix Number of Non-Zero Elements.
    */
    //Number of elements are same for row - major or colom major.
    M->A = new int[n*(n+1)/2]();
    
    //Taking Elements and Calling Set Function.
    //Watch out for starting index
    int k;
    for(int i=1; i<= M->n;i++) {
        for(int j=1;j<=M->n;j++) {
            cin >> k;
            if(row) {
                set_lower_tri(M, i, j, k, true);
            } else {
                set_lower_tri(M, i, j, j, false);
            }
        }
    }
}

void set_lower_tri(Matrix* M, int i, int j, int k, bool row) {
    //only those indexes will have elements where i >= j
    int index;
    if(i>=j) {
        if(row) {
            index = i*(i-1)/2 + j-1;
        } else {
            index = M->n*(j-1) - (j-2)*(j-1)/2 + (i-j);
        }
        M->A[index] = k;
    } 
    //Else matrix is already initialized to 0.
}

int get_lower_tri(const Matrix* M, int i, int j, bool row) {
    int index;
    if(i>=j) {
        if(row) {
            index = i*(i-1)/2 + (j-1);
        } else {
            index = M->n*(j-1) - (j-1)*(j-2)/2 + (i-j);
        }
        return M->A[index];
    }
    //ELSE RETURNING 0 iS MANDATORY AS THIS IS THE CRUX OF THE ALGO. 
    else {
        return 0;
    }
}

void display_lower_tri(const Matrix* M, bool row) {
    //Watch out please starting from 1
    for(int i=1;i<=M->n;i++) {
        for(int j=1;j<=M->n;j++) {
            if(row) {
                cout << get_lower_tri(M, i, j, true) << " ";
            } else {
                cout << get_lower_tri(M, i, j, false) << " ";
            }
        }
        cout << endl;
    }
}

/*
    - Lower Triangular Matrix Callers
*/

void row_major_caller_lower_tri(Matrix* M) {
    create_lower_tri(M,true);
    cout << "Row Major Lower Triangular Matrix is Set. Displaying Now: " << endl;
    cout << ">===>MATRIX:" << endl;
    display_lower_tri(M, true);

}

void col_major_caller_lower_tri(Matrix* M) {
    create_lower_tri(M,false);
    cout << "Col Major Lower Triangular Matrix is Set. Displaying Now: " << endl;
    cout << ">===>MATRIX:" << endl;
    display_lower_tri(M,false);
}

void _lower_triangular_matrix() {
    cout << "Lower Triangular Matrix: M[i][j] == 0 if i < j; M[i][j] != 0 if i >= j;" << endl;
    cout << "LTM could be stored as either Row Major or Colom Major."<<endl;
    int choice=0,done=0;
    Matrix M;
    do {
        cout << "1. Row Major Setting: i*(i-1)/2 + j-1" << endl;
        cout << "2. Col Major Setting: n*(j-1) - (j-2)*(j-1)/2 + (i-j)" << endl;
        cin >> choice;
    }while(choice != 1 && choice !=2);

    if(choice == 1) {
        row_major_caller_lower_tri(&M);
    } else {
        col_major_caller_lower_tri(&M);
    }
    delete [] M.A;
}

// /*
// *************Upper Triangular Matrix**********
// */

void create_upper_tri(Matrix* M, bool row) {
    int n;
    cout << "Enter dimension:: ";
    cin >> n;
    M->n=n;
    /*
        Upper Triangular Matrix Number of Non-Zero Elements.
    */
    //Number of elements are same for row - major or colom major.
    M->A = new int[n*(n+1)/2]();
    int k;
    //Taking Elements and Calling Set Function.
    //Watch out for starting index
    for(int i=1;i<=M->n;i++) {
        for(int j=1;j<=M->n;j++) {
            cin >> k;
            if(row) {
                set_upper_tri(M, i, j, k, true);
            } else {
                set_upper_tri(M, i, j, k, false);
            }
        }
    }
}

void set_upper_tri(Matrix* M, int i, int j, int k, bool row) {
    int index;
    if(i<=j) {
        if(row) {
            index = (i-1)*(M->n) - (i-2)*(i-1)/2 + (j-i); 
        } else {
            //careful it is alway in -
            index = j*(j-1)/2 + i-1;
        }
        M->A[index] = k;
    } else {
        M->A[index] = 0;
    }
}

int get_upper_tri(const Matrix* M, int i, int j, bool row) {
    int index;
    if(i<=j) {
        if(row) {
            index = (i-1)*(M->n) - (i-2)*(i-1)/2 + (j-i);
        } else {
            index = j*(j-1)/2 + (i-1);
        }
        return M->A[index];
    } else {
        return 0;
    }
}

void display_upper_tri(const Matrix* M, bool row) {
    //Watch out index starting from 1.
    for(int i=1;i<=M->n;i++) {
        for(int j=1;j<=M->n;j++) {
            if(row) {
                cout << get_upper_tri(M, i, j, true) << " ";
            } else {
                cout << get_upper_tri(M, i, j, false) << " ";
            }
        }
        cout << endl;
    }
}

void row_major_caller_upper_tri(Matrix* M) {
    create_upper_tri(M,true);
    cout << "Row Major Upper Triangular Matrix is Set. Displaying Now: " << endl;
    cout << ">===>MATRIX:" << endl;

    display_upper_tri(M, true);

}

void col_major_caller_upper_tri(Matrix* M) {
    create_upper_tri(M,false);
    cout << "Col Major Upper Triangular Matrix is Set. Displaying Now: " << endl;
    cout << ">===>MATRIX:" << endl;
    display_upper_tri(M,false);
}

void _upper_triangular_matrix() {
    cout << "Upper Triangular Matrix: M[i][j] == 0 if i > j; M[i][j] != 0 if i <= j." << endl;
    cout << "UTM could be stored as either Row Major or Colom Major."<<endl;
    cout << "Note: As there are more elements in colums of a Upper triangular matrix. Therefore, coloum major formula will be simpler." << endl;
    int choice=0,done=0;
    Matrix M;
    do {
        cout << "1. Row Major Setting(i will be King): (i-1)*n - (i-1)*(i-2)/2 + (j-i)" << endl;
        cout << "2. Col Major Setting(j will be King): j*(j-1)/2 + (i-1)" << endl;
        cin >> choice;
    }while(choice != 1 && choice !=2);

    if(choice == 1) {
        row_major_caller_upper_tri(&M);
    } else {
        col_major_caller_upper_tri(&M);
    }
    delete [] M.A;
}

/*
    - MAIN
*/

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
            break;
        case 3:
            _upper_triangular_matrix();
            break;
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
        case -1:
            cout << "Thank You for Visiting the World of Matrices! :)" << endl; 
    }

}