#include<iostream>
#include<string>
#include "Date.h"
using namespace std;

//initialized static member first
const array<unsigned int, 13> Date::days{
    0,31,28,31,30,31,30,31,31,30,31,30,31
};

Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}

//set month, day, year
void Date::setDate(int mm, int dd, int yy) {
   if (mm >= 1 && mm <= 12) {
      month = mm;
   }
   else {
      throw invalid_argument{"Month must be 1-12"};
   }

   if (yy >= 1900 && yy <= 2100) {
      year = yy;
   }
   else {
      throw invalid_argument{"Year must be >= 1900 and <= 2100"};
   }

   // test for a leap year
   if ((month == 2 && leapYear(year) && dd >= 1 && dd <= 29) ||
      (dd >= 1 && dd <= days[month])) {
      day = dd;
   }
   else {
      throw invalid_argument{
         "Day is out of range for current month and year"};
   }
}

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int testYear) {
   return (testYear % 400 == 0 ||
      (testYear % 100 != 0 && testYear % 4 == 0));
}

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
   if (month == 2 && leapYear(year)) {
      return testDay == 29; // last day of Feb. in leap year
   }
   else {
      return testDay == days[month];
   }
}

Date& Date::operator++() {
    helpIncrement();
    return *this; //help cascadeing
}

Date Date::operator++(int) {
    Date temp = *this;
    helpIncrement();
    return temp;
}

void Date::helpIncrement() {
   // day is not end of month
   if (!endOfMonth(day)) {
      ++day; // increment day
   }
   else {
      if (month < 12) { // day is end of month and month < 12
         ++month; // increment month
         day = 1; // first day of new month
      }
      else { // last day of year
         ++year; // increment year
         month = 1; // first month of new year
         day = 1; // first day of new month
      }
   }
}

ostream& Date::operator<<(const ostream& output, const Date& d) {
    static string monthName[13]{"", "January", "February",
      "March", "April", "May", "June", "July", "August",
      "September", "October", "November", "December"};
   output << monthName[d.month] << ' ' << d.day << ", " << d.year;
   return output
}
