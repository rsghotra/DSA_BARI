#include<iomanip>
#include<stdexcept>
#include<sstream>
#include "CommissionEmployee.h"
using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate) {
        this->firstName = first;
        this->lastName = last;
        this->socialSecurityNumber = ssn;
        setGrossSales(sales);
        setCommissionRate(rate);
    }

void CommissionEmployee::setFirstName(const string& first) {
    this->firstName = first;
}

string CommissionEmployee::getFirstName() const {
    return this->firstName;
}

void CommissionEmployee::setLastName(const string& last) {
    this->lastName = last;
}

string CommissionEmployee::getLastName() const {
    return this->lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string& ssn) {
    this->socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const {
    return this->socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sale) {
    if(sale < 0.0) {
        throw invalid_argument("Gross sales must be >= 0.0");
    }
    grossSales = sale;
}

double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate) {
    if(rate <= 0.0 || rate >= 1.0) {
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }
    commissionRate = rate;
}

double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

double CommissionEmployee::earning() const {
    return commissionRate * grossSales;
}

string CommissionEmployee::toString() const {
    ostringstream output;

    output << fixed << setprecision(2);
    output << "commission employee: " << firstName << " " << lastName
        << "\nsocial security number: " << socialSecurityNumber
        << "\ngross sales: " << grossSales
        << "\ncommission rate: " << commissionRate;
    return output.str();
}

