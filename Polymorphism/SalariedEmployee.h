#ifndef SALARIED_H
#define SALARIED_H
#include "Employee.h"
class SalariedEmployee : public Employee{
public:
    SalariedEmployee(const std::string&, const std::string&, const std::string&, double = 0.0);
    //forcing it to be a default destructor
    virtual ~SalariedEmployee() = default;

    void setWeeklySalary(double);
    double getWeeklySalary() const;

    //MUST override earning as it is a pure virtual function
    virtual double earning() const override;
    virtual std::string toString() const override;
private:
    double weeklySalary;
};


#endif
