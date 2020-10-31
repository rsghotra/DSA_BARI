/*
- Sparse matrix of MxN dimension with mostly filled with zeros

*/
#include <iostream>
using namespace std;

/*Element of sparse matrix could be represented by a struct
    - create a sparse matrix
    - display a sparse matrix
    - sum two sparse matrices
*/
struct Element {
    int i;
    int j;
    int val;
};

struct Sparse {
    int m;
    int n;
    int num_non_zeros;
    Element* ele;
};

void create(Sparse*);
void display(Sparse);
Sparse sum(Sparse s1, Sparse s2);


void create(Sparse* sp) {
    cout << "Enter Dimensions: "<<endl;
    cin >> sp->m >> sp->n;
    cout << "Please enter number of non-zero elements. ";
    cin >> sp->num_non_zeros;
    sp->ele = new Element[sp->num_non_zeros];
    for(int i=0;i<sp->num_non_zeros;i++) {
        cout << "Enter tuple<row#,col#,val> Number " << i+1 << " of " << sp->num_non_zeros <<  " non-zero elements: ";
        cin >> sp->ele[i].i >> sp->ele[i].j >> sp->ele[i].val; 
    }
    cout << "Sparse matrix created successfully!" << endl;
}

// how to display the values of a sparse matrix - we just simply have to iterate over the struct of sparse matrix and when i and j matches simply print.

int main() {
    Sparse sp1, sp2;
    create(&sp1);
    cout <<"Displaying the matrix==>>" << endl;
    display(sp1);
}