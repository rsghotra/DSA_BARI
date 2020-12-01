//Abstract-base-class Employee member-function definitions.
//Note: No definitions are given for virtual functions
#include<sstream>
#include<iomanip>
#include "Employee.h"
#include<iostream>
using namespace std;

Employee::Employee(const string& first, const string& last, const string& ssn)
        : firstName{first}, lastName{last}, socialSecurityNumber{ssn} {}

Employee::~Employee(){}

void Employee::setFirstName(const string& name) {
    this->firstName = name;
}

string Employee::getFirstName() const {
    return this->firstName;
}

void Employee::setLastName(const string& name) {
    this->lastName = name;
}

string Employee::getLastName() const {
    return this->lastName;
}

void Employee::setSocialSecurityNumber(const string& num) {
    this->socialSecurityNumber = num;
}

string Employee::getSocialSecurityNumber() const {
    return this->socialSecurityNumber;
}

string Employee::toString() const {
    ostringstream output;
    output << getFirstName() << setw(2) << getLastName() << "\nsocial security number:" << setw(2) << getSocialSecurityNumber();
    return output.str(); 
}
