#ifndef BASEPLUS_H
#define BASEPLUS_H
#include "CommissionEmployee.h"
#include<string>

class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary;
public:
    BasePlusCommissionEmployee(const std::string&, const std::string&, const std::string&, 
    double = 0.0, double = 0.0, double = 0.0);
    virtual ~BasePlusCommissionEmployee() = default;


    void setBaseSalary(double);
    double getBaseSalary() const;

    virtual double earning() const override;
    virtual std::string toString() const override;
    
};

#endif