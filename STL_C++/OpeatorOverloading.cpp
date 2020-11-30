#include<iostream>
#include<iomanip>
#include<string>

/*
OPERATOR OVERLOADING

1. Operator Overloading can be done in two ways
    by creating a friend function or by creating a member function

2. When overloading binary operator such as <
    - Compiler converts y < z as:
        y.operator<(z);
    
    < Operator Signature when it is a member function
    class String {
        public:
            bool operator<(const String&) const;
    }

    < Opertor Overloading function when it will be a friend function

    bool operator<(const obj&, const obj&);

3. Overloading Binary Stream Insertion and Extration Operator

4. Overloading Unary Operator s.operator!()
    bool opeator!(const obj&) const;
5. Overloading prefix
     obj& operator++(obj&);
     obj& operator++();
6. Overloaing Postfix
    obj& operator++(obj&, int)
    obj& operator++(int)
7.  

*/

using namespace std;

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

class PhoneNumber {
    friend ostream& operator<<(ostream&, const PhoneNumber&);
    friend istream& operator>>(istream&, PhoneNumber&);

    private:
        string areaCode;
        string exchange;
        string line;
};

#endif

ostream& operator<<(ostream& output, const PhoneNumber& number) {
    output << "Area Code: " << number.areaCode << "\nExchange: " << number.exchange
        << "\nLine: " << number.line << "\n" << "(" << number.areaCode << ")" << number.exchange
            << "-" << number.line << "\n";
    return output; // enables cascading cout << a << b << c;
}

//overloaded stream extraction operator; cannot be member function
//if we would like to invole it with cin >> somePhoenNumber

istream& operator>>(istream& input, PhoneNumber& number) {
    input.ignore();
    input >> setw(3) >> number.areaCode;
    input.ignore(2);
    input >> setw(3) >> number.exchange;
    input.ignore();
    input >> setw(4) >> number.line;
    return input; //enables cin >> a >> b >> c; 
}


int main() {
    PhoneNumber phone;

    cout << "Enter phone number in the form (555) 555-5555: " << endl;

    //cin >> phone involes operato>> by implicityly issuing
    //the non-member function call operator>>(cin, phone)
    cin >> phone;

    //cin << phone involes operato<< by implicityly issuing
    //the non-member function call operator<<(cout, phone)
    cout << phone << endl;
}