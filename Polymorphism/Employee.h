#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

class Employee {
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
public:
    Employee(const std::string&, const std::string&, const std::string&);
    virtual ~Employee(); //virtual destructor. Now, an derived class's destructor will be virtual as well
    void setFirstName(const std::string&);
    std::string getFirstName() const; //return first name

    void setLastName(const std::string&);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string&);
    std::string getSocialSecurityNumber() const;

    //made virtual function
    virtual double earning() const = 0;
    virtual std::string toString() const;
};
#endif