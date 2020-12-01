#include<iostream>
#include<iomanip>
#include<vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

void virtualViaPointer(const Employee* const);
void virtualViaRef(const Employee&);

int main() {
    cout << fixed << setprecision(2);
    SalariedEmployee  salariedEmployee{"John", "Smith", "234-123-221", 800};

    CommissionEmployee commissionEmployee{"Alex", "Sen", "123-456-789", 10000, .06};

    BasePlusCommissionEmployee basePlusCommission{"Ruhi", "Joshi", "234-879-888", 5000, .04, 300};

    cout << "\nEMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
        << salariedEmployee.toString()
        << "\nearned $" << salariedEmployee.earning() << "\n\n"
        << commissionEmployee.toString()
        << "\nearned $" << commissionEmployee.earning() << "\n\n"
        << basePlusCommission.toString()
        << "\nearned $" << basePlusCommission.earning() << "\n\n";

    //initializing vector of three base-class pointers
    vector<Employee*> employees;
    employees.push_back(&salariedEmployee);
    employees.push_back(&commissionEmployee);
    employees.push_back(&basePlusCommission);

    cout << "\nEMPLOYEES PROCESSES POLYMORPHICALLY VIA DYNAMIX BINDING\n\n" << flush;

    cout << "\nVIRTUAL FUNCTION CALLS MADE OFF BASE CLASS PTR\n" << flush;

    for(const Employee* employeePtr: employees) {
        virtualViaPointer(employeePtr);
    }

    cout << "\nVIRTUAL FUNCTION CALL MADE OFF BASE CLASS REFERENCES\n\n";

    for(const Employee* employeePtr: employees) {
        virtualViaRef(*employeePtr);
    }



    /*
        - Increase base salary of baseplus commission by 10/ use downcasting
    */
   cout << "\n>==>>>>>>" << endl;
   for(Employee* employeePtr: employees) {
       cout << employeePtr->toString() << endl;

       BasePlusCommissionEmployee* derivedPtr = dynamic_cast<BasePlusCommissionEmployee*>(employeePtr);

       if(derivedPtr != nullptr) {
           double oldBaseSalary = derivedPtr->getBaseSalary();
           cout << "\nold base salary: $" << oldBaseSalary << endl;
           derivedPtr->setBaseSalary(1.10*oldBaseSalary);
           cout << "new base salary with 10% increase is: $"
                << setw(2) << derivedPtr->getBaseSalary() << endl;
       }

       cout << "earned $" << employeePtr->earning();
   }

   for(const Employee* employeePtr: employees) {
       cout << "\nDeleting object of" << typeid(*employeePtr).name() << endl;
       delete employeePtr;
   }


}   

void virtualViaPointer(const Employee* const baseClassPtr) {
    cout << baseClassPtr->toString()
        << "\nearned $" << baseClassPtr->earning();
}

void virtualViaRef(const Employee& baseClassRef) {
    cout << baseClassRef.toString() 
        << "\nearned\n" << baseClassRef.earning();
}