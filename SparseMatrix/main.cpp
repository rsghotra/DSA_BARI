#include<iostream>
using namespace std;

struct Element {
    int i;
    int j;
    int data;
};

struct Sparse {
    int m;
    int n;
    int num_of_non_zeros;
    Element* E;
};

Sparse* Create(Sparse* sp) {
    cout << "Enter number of rows and cols of the Sparse Matrix: ";
    cin >> sp->m >> sp->n;

    cout << "Enter number of non zero elements: " ;
    cin >> sp->num_of_non_zeros;

    //create matrix now
    sp->E = new Element[sp->num_of_non_zeros];

    for(int i{0}; i < sp->num_of_non_zeros; ++i) {
        cout << "\nEnter <row# col# data> for " << i + 1 << " non zeroth element: ";
        cin >> sp->E[i].i >> sp->E[i].j >> sp->E[i].data;
    }
}

Sparse* Add(Sparse* sp1, Sparse* sp2) {
    /*
        Validate:
            - sp1.m == sp2.m
            - sp1.n == sp1.n
        Output Elements DS: Could have maximum possible elements = number of nonzeros in sp1 + sp2
        Number of non zero elements of output matrix will only come to know
    */
   if(sp1->m == sp2->m && sp1->n == sp2->n) {
       //matrix inititialization
       int i = 0;
       int j = 0;
       int k = 0; 
       Sparse* sp3 = new Sparse;
       sp3->m = sp1->m;
       sp3->n = sp1->n;
       sp3->E = new Element[sp1->num_of_non_zeros+sp2->num_of_non_zeros];

       while(i < sp1->num_of_non_zeros && j < sp2->num_of_non_zeros) {
           //check if incominng entries are suitable for addition
           if(sp1->E[i].i == sp2->E[j].i && sp1->E[i].j == sp2->E[j].j) {
               sp3->E[k].i = sp1->E[i].i;
               sp3->E[k].j = sp1->E[i].j;
               sp3->E[k].data = sp1->E[i].data + sp2->E[j].data;
               i++;
               j++;
               k++;
               sp3->num_of_non_zeros++;
           } else if(sp1->E[i].i <sp2->E[j].i) {
               sp3->E[k] = sp1->E[i];
               sp3->num_of_non_zeros++;
               i++;
               k++;
           } else {
               sp3->E[k] = sp2->E[j];
               sp3->num_of_non_zeros++;
               j++;
               k++;
           }
       }
       while(i < sp1->num_of_non_zeros) {
            sp3->E[k] = sp1->E[i];
            sp3->num_of_non_zeros++;
            i++;
            k++;
       }
       while(j < sp2->num_of_non_zeros) {
            sp3->E[k] = sp2->E[j];
            sp3->num_of_non_zeros++;
            j++;
            k++;
       }
       return sp3;
   }
   cout << "\nFor ADD of Two MATRIX A and B; Their Dimensions must be same; A = MxN and B=MxN." << endl;
   return nullptr;
}

Sparse* Multiply(Sparse* sp1, Sparse* sp2) {
    if(sp1->n == sp2->m) {
        //new matrix initialization
        Sparse* sp3 = new Sparse();
        sp3->m = sp1->m;
        sp3->n = sp2->n;
        sp3->E = new Element[sp1->num_of_non_zeros+sp2->num_of_non_zeros];
        int i = 0; //track first
        int j = 0; //track second
        int k = 0; //track third
        int sum;
        //multiplicatoin of matrices is controlled by
        //row of Matrix 1
        //col of Matrix 2
        for(int u = 1; u <= sp1->m; u++) {
            for(int v = 1; v <= sp2->n; v++) {
                sp3->E[k].i = u;
                sp3->E[k].j = v;
                sp3->E[k].data = sum;
                k++;
            }
            for(int i = 0; i < sp1->num_of_non_zeros; i++) {
                if(sp1->E[i].i == u) {
                    sum =0;
                    for(j=0; j< sp2->num_of_non_zeros; j++) {
                        if(sp1->E[i].i == sp2->E[j].j) {
                            sum += sp1->E[i].data * sp2->E[j].data;
                        }
                    }
                    sp3->E[k].i = sp1->E[i].i;
                    sp3->E[k].j = sp1->E[j].j;
                    sp3->E[k].data = sum;
                    k++;
                    sp3->num_of_non_zeros++;
                }
            }
        }
        return sp3;
    }
    cout << "\nMultiplictation of Matrix is possible only if: A: MxN and B: NxP ==> C: MxP." << endl;
    return nullptr;
}

void Print(Sparse* sp) {
    int k=0;
    if(sp) {
        for(int i{1}; i<=sp->m; ++i) {
            for(int j{1}; j <= sp->n; ++j) {
                if(sp->E[k].i == i && sp->E[k].j == j) {
                    cout << sp->E[k].data << " ";
                    k++;
                } else {
                    cout <<  "0 ";
                }
            }
            cout << endl;
        }
    }
}

int main() {
    Sparse s1, s2;

    Create(&s1);
    Create(&s2);

    cout << "\nPrinting first sparse matrix." << endl;
    Print(&s1);
    cout << "\nPrinting second sparse matrix." << endl;
    Print(&s2);

    Sparse* s3 = Add(&s1, &s2);
    cout << "\nPrinting Addition of two sparse matrix." << endl;
    Print(s3);
    cout << "\nPrinting Multiplication of two sparse matrix." << endl;
    Sparse* s4 = Multiply(&s1, &s2);
    Print(s4);
}