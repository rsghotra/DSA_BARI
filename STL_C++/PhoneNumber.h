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

*/

//this program assumes that the number entered is correct
