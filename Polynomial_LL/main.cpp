#include<iostream>
#include<cmath>
using namespace std;
/*
 - Polynomial representation using Linked List
*/

struct Term {
    int coefficiant;
    int exponent;
    Term* next;
};

struct Polynomial {
    int num_of_terms;
    Term* t;
};

void display(const Polynomial* poly) {
    if(!poly) return;
    Term* temp = poly->t;
    while(temp) {
        cout << temp->coefficiant << "X" << temp->exponent << " + ";
        temp = temp->next;
    }
    cout << endl;
}

void eval(Polynomial* poly, int x) {
    if(!poly) return;
    int val = 0;
    Term* temp = poly->t;
    while(temp) {
        val += temp->coefficiant * pow(x,temp->exponent);
        temp = temp->next;
    }
    cout << "The value of the polynomial is: " << val << endl;
}

int main() {
    Polynomial poly;
    cout << "How many terms in the polynomial do you have?" << endl;
    cin >> poly.num_of_terms;
    poly.t = new Term;
    cout << "Please enter coefficiant of first term" << endl;
    cin >> poly.t->coefficiant;
    cout << "Please enter exponent of first term" << endl;
    cin >> poly.t->exponent;
    poly.t->next = NULL;
    Term* last = poly.t;
    Term* n;
    for(int i = 2; i<=poly.num_of_terms;i++) {
        n = new Term;
        cout << "Please enter coefficiant of " << i << " term: " << endl;
         cin >> n->coefficiant;
         cout << "Please enter exponent of " << i << " term: " << endl;
         cin >> n->exponent;
         last->next = n;
         last = n;
         n->next = NULL;
    }
    display(&poly);
    int x;
    cout << "For what value of x would you like to evaluate the polynomial?" << endl;
    cin >> x;
    eval(&poly, x);
}