#include "CommissionEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    CommissionEmployee employee{"Sue", "Jones", "226-789-7738", 10000, .06};

    //get commision employee data

    cout << fixed << setprecision(2);

    cout << "Employee information obtaine dby get functions: \n"
        << "\nFirst Name: " << employee.getFirstName()
        << "\nLast Name: " << employee.getLastName()
        << "\nSocial Security Number: " << employee.getSocialSecurityNumber()
        << "\nGross sales is " << employee.getGrossSales()
        << "\nCommission rate is " << employee.getCommissionRate() << endl;
    
    employee.setCommissionRate(.1);
    employee.setGrossSales(8000);

    cout << "\nUpdated employee information from function toString() \n\n"
        << employee.toString();
    cout << "\n\nEmployee's earnings: $" << employee.earning() << endl;
}