#include<iomanip>
#include<string>
#include "CommissionEmployee.h"
using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate) 
    : Employee(first, last, ssn) {
        this->setGrossSales(sales);
        this->setRate(rate);
}

void CommissionEmployee::setGrossSales(double sales) {
    if(sales < 0.0) {
        throw invalid_argument("Sales can not be negative, must be >= 0.0");
    }
    this->grossSales = sales;
}

void CommissionEmployee::setRate(double rate) {
    if(rate < 0.0 || rate > 1.0) {
        throw invalid_argument("Rate can not be negative, must be > 0.0");
    }
    this->rate = rate;
}

double CommissionEmployee::getGorssSales() const {
    return this->grossSales;
}

double CommissionEmployee::getRate() const {
    return this->rate;
}

double CommissionEmployee::earning() const {
    return (this->getGorssSales() * this->getRate());
}

string CommissionEmployee::toString() const {
    ostringstream output;
    output << fixed << setprecision(2);
    output << "\ncommission employee:" << setw(2)
        << Employee::toString() << "\nEarning:" << setw(2) << earning();
    return output.str();
}



