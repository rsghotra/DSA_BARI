#include<iostream>
#include<iomanip>
#include<sstream>
#include "BasePlusCommissionEmployee.h"
using namespace std;


BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn,
    double grossSales, double rate, double baseSalary) : CommissionEmployee(first, last, ssn, grossSales, rate) {
    this->setBaseSalary(baseSalary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    this->baseSalary = salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return this->baseSalary;
}

double BasePlusCommissionEmployee::earning() const {
    return getBaseSalary() + CommissionEmployee::earning();
}

string BasePlusCommissionEmployee::toString() const {
    ostringstream output;
    output << fixed << setprecision(2);
    output << "\nbasepluscommissionemployee:" << setw(2)
        << CommissionEmployee::toString() << 
        "\nbasesalary: " << getBaseSalary();

    return output.str();
}



