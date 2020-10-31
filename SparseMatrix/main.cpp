/*
- Sparse matrix of MxN dimension with mostly filled with zeros

*/
#include <iostream>
using namespace std;

/*Element of sparse matrix could be represented by a struct
    - Represent  using three coloum method
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
Sparse* sum(Sparse s1, Sparse s2);


void create(Sparse* sp) {
    cout << "Enter Dimensions: "<<endl;
    cin >> sp->m >> sp->n;
    cout << "Please enter number of non-zero elements. ";
    cin >> sp->num_non_zeros;
    sp->ele = new Element[sp->num_non_zeros];
    //WATCHOUT THIS will be tricky. As we are storing the elements in  struct
    for(int i=0;i<sp->num_non_zeros;i++) {
        cout << "Enter tuple<row#,col#,val> Number " << i+1 << " of " << sp->num_non_zeros <<  " non-zero elements: ";
        cin >> sp->ele[i].i >> sp->ele[i].j >> sp->ele[i].val; 
    }
    cout << "Sparse matrix created successfully!" << endl;
}

// how to display the values of a sparse matrix - we just simply have to iterate over the struct of sparse matrix and when i and j matches simply print.
void display(const Sparse sp) {
    //Remember; IT IS CONFUSING: Four things to consider:
    /*
        1. Two nested for loops with 0s inserted by us.
        2. Remember at the time of displaying the user had entered the matrices from starting index 1.
        3. You actually need three variables
    */
   int k = 0,i, j;
   for(i = 1; i <= sp.m;i++) {
       for(j = 1; j <= sp.n;j++) {
           //LOOK CAREFULLY ITERATIVE OVER K AND I AND J
           if(sp.ele[k].i == i && sp.ele[k].j == j) {
               cout << sp.ele[k].val << " ";
               k++;
           } else {
               cout << 0 << " ";
           }
       }
       cout << endl;
   }
}

Sparse* sum(Sparse sp1, Sparse sp2) {
    //check if addition of given matrix is possible
    if(sp1.m == sp2.m && sp1.n == sp2.n) {
        //lets initialize the third matrix
        int i=0, j=0, k=0;
        Sparse* sp3 = new Sparse();
        sp3->m = sp1.m;
        sp3->n = sp1.n;
        sp3->num_non_zeros = 0; // initializing to zero as I do not know the number exactly.
        //I do know that MAX num no non zero terms and I will create a dynamic array of this size.
        sp3->ele = new Element[sp1.num_non_zeros + sp2.num_non_zeros];
        while(i<sp1.num_non_zeros && j < sp2.num_non_zeros) {
            //if first matrix row is smaller then we copy first matrix's element to sp3
            if(sp1.ele[i].i < sp2.ele[j].i) {
                sp3->ele[k] = sp1.ele[i];
                k++;
                i++;
                sp3->num_non_zeros++;
            } else if(sp1.ele[i].i > sp2.ele[j].i) {
                //copy second matrix
                sp3->ele[k] = sp2.ele[j];
                k++;
                j++;
                sp3->num_non_zeros++;
            } else { //when row is same we must check for coloum as well
                //when row same, coloum is small of first matrix
                if(sp1.ele[i].j < sp2.ele[j].j) {
                    sp3->ele[k] = sp1.ele[i];
                    k++;
                    i++;
                    sp3->num_non_zeros++;
                } else if(sp1.ele[i].j > sp2.ele[j].j) {
                    sp3->ele[k] = sp2.ele[j];
                    k++;
                    j++;
                    sp3->num_non_zeros++;
                } else {
                    //both rows and coloum are same number
                    //make copy
                    sp3->ele[k].i = sp1.ele[i].i;
                    sp3->ele[k].j = sp1.ele[i].j;
                    sp3->ele[k].val = sp1.ele[i].val + sp2.ele[j].val;
                    k++;
                    i++;
                    j++;
                    sp3->num_non_zeros++;
                }
            }
        }
        //copy any of the pending array
        while(i < sp1.num_non_zeros) {
            sp3->ele[k] = sp1.ele[i];
            sp3->num_non_zeros++;
            k++;
            i++;
        }
        while(j < sp2.num_non_zeros) {
            sp3->ele[k] = sp2.ele[i];
            sp3->num_non_zeros++;
            k++;
            j++;
        }
        return sp3;
    }
    return nullptr;
}

int main() {
    Sparse sp1, sp2;
    cout << "Welcome to Sparse Matrix. We will see SUM operation on two Sparse Matrices." << endl;
    cout << "Please enter first sparse matrix(Note index starts from 1)." << endl;
    create(&sp1);
    cout << "Please enter second sparse matrix(Note index starts from 1)." << endl;
    create(&sp2);
    Sparse* sp3 = sum(sp1, sp2);
    cout << "=================================" <<endl;
    cout << ">==>First Matrix."<<endl;
    display(sp1);
    cout << ">==>Second Matrix."<<endl;
    display(sp2);
    cout << ">==>SUM of Two Sparse Matrices: " << endl;
    display(*sp3);
    return 0;
}