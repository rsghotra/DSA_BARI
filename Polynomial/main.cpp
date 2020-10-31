/*
Polynomial Representation Using Struct or array of struct
    - P(x) = 5x^4 + 2x^3 + 6x^2 + 2x + 1;
    - A univariate polynomial is a collection of n terms
    - A term is made up of coefficiant and exponent.
    - We only add two polynomials if the exponent matches.
    - We study three thigs -
        - Representation of Polynomial
        - Displaying Polynomial
        - Addition of two polynomials
*/
#include<iostream>
using namespace std;

struct Term {
    int coefficiant;
    int exponent;
};

struct Polynomial {
    int num_of_terms;
    Term* t;
};

void create(Polynomial*);
void display(Polynomial);
Polynomial* sum(Polynomial,Polynomial);

void create(Polynomial* p) {
    cout << "Enter # of terms polynomial has: ";
    cin >> p->num_of_terms;
    cout << endl;
    p->t = new Term[p->num_of_terms];
    int i=0;
    for(i;i<p->num_of_terms;i++) {
        cout << "Enter coefficiant and exponent of " << i+1 << " term." << endl;
        cin >> p->t[i].coefficiant >> p->t[i].exponent;
    }
    cout << "Polynomial is stored nicely!" << endl;
}

void display(Polynomial p) {
    int i=0;
    for(i;i<p.num_of_terms - 1;i++) {
        cout << p.t[i].coefficiant << "X" << p.t[i].exponent << " + ";
    }
    cout << p.t[i].coefficiant << "X" << p.t[i].exponent << endl;
}

Polynomial* sum(Polynomial p1, Polynomial p2) {
    Polynomial* p3 = new Polynomial();
    //taking max possible number of terms which is m+n
    p3->num_of_terms=0; //we will absolute number of terms in here and not approximate
    p3->t = new Term[p1.num_of_terms+p2.num_of_terms];
    int i=0,j=0,k=0;
    //a standard merge of arrays
    while(i<p1.num_of_terms && j<p2.num_of_terms) {
        if(p1.t[i].exponent > p2.t[j].exponent) {
            p3->t[k] = p1.t[i];
            k++;
            i++;
            p3->num_of_terms++;
        } else if(p2.t[j].exponent > p1.t[i].exponent) {
            p3->t[k] = p2.t[j];
            k++;
            j++;
            p3->num_of_terms++;
        }
        if(p1.t[i].exponent == p2.t[j].exponent) {
            //addition is possible
            p3->t[k].coefficiant = p1.t[i].coefficiant + p2.t[j].coefficiant;
            p3->t[k].exponent = p1.t[i].exponent;
            k++;
            i++;
            j++;
            p3->num_of_terms++;
        }
    }
    //copy rest of them
    while(i<p1.num_of_terms) {
        p3->t[k] = p1.t[i];
        k++;
        i++;
        p3->num_of_terms++;
    }
    while(j<p2.num_of_terms) {
        p3->t[k] = p2.t[j];
        k++;
        j++;
        p3->num_of_terms++;
    }
    return p3;
}

int main() {
    cout << "Welcome to Univariate Polynomial! Program will take two univariate polynomials by first asking for number of terms in each polynomial." << endl;
    Polynomial p1, p2,*p3;
    create(&p1);
    create(&p2);
    p3 = sum(p1,p2);
    cout << "==>First Univariate Polynomial P1(x)=";
    display(p1);
    cout << "==>Second Univariate Polynomial P2(x)=";
    display(p2);
    cout << "==>Sum of P1+P2; P3(x)=";
    display(*p3);
}