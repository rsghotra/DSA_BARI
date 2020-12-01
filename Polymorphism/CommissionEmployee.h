#ifndef COMMISSION_H
#define COMMISSION_H
#include "Employee.h"
#include<string>

class CommissionEmployee: public Employee {
private:
    double grossSales;
    double rate;
public:
    CommissionEmployee(const std::string&, const std::string&, const std::string&, double = 0.0, double = 0.0);
    virtual ~CommissionEmployee() = default;

    void setGrossSales(double);
    double getGorssSales() const;

    void setRate(double);
    double getRate() const;

    virtual double earning() const override;
    virtual std::string toString() const override;
};

#endif