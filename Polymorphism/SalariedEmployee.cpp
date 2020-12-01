#include<iomanip>
#include<iostream>
#include<sstream>
#include<stdexcept>
#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee(const string& first, const string& last, const string& ssn, double salary) : Employee(first, last, ssn) {
    this->setWeeklySalary(salary);
}

void SalariedEmployee::setWeeklySalary(double salary) {
    if(salary < 0.0) {
        throw invalid_argument("Salary has to be greater than 0");
    }
    weeklySalary = salary;
}

double SalariedEmployee::getWeeklySalary() const {
    return this->weeklySalary;
}

//donot need to write a virtual and ovveride keyword in .cpp file. Because already written in .h file

double SalariedEmployee::earning() const  {
    return getWeeklySalary();
}

string SalariedEmployee::toString() const {
    ostringstream output;
    output << fixed << setprecision(2);
    output << "salaried employee:" << setw(2) << Employee::toString() << "\nweekly salary: " << getWeeklySalary();
    return output.str();
}
