#include<string>
#include<iostream>
#include<sstream>
using namespace std;
#ifndef DATE_H
#define DATE_H

class Date {
    private:
        unsigned int month;
        unsigned int day;
        unsigned int year;
    public:
        explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2000);
        string toString() const;
};

Date::Date(unsigned int m, unsigned int d, unsigned int y): month{m}, year{y}, day{d}{}

//prints data in mm/dd/yyyy format
string Date::toString() const {
    ostringstream output;
    output << month << "/" << day << "/" << year;
    return output.str();
}

int main() {
    Date date1{7,4,2004};
    Date date2;

    cout << "date1 = " << date1.toString()
        << "\ndate2 = " << date2.toString() << "\n\n";

    date2 = date1;
    cout << "After default member wise assignment, date2 = " << date2.toString() << endl;
}

#endif