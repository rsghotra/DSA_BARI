#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>
#include<iomanip>
using namespace std;
#ifndef TIME_H
#define TIME_H

class Time {
    public:
        explicit Time(int = 0, int = 0, int = 0);
        void setTime(int, int, int);
        void setHour(int);
        void setMinute(int);
        void setSecond(int);

        unsigned int getHour() const { return hour;}
        unsigned int getMinute() const;
        unsigned int getSecond() const;

        unsigned int& badSetHour(int); //dangerous reference return

        std::string toUniversalString() const;
        std::string toStandardString() const;
    private:
        unsigned int hour{0};
        unsigned int minute{0};
        unsigned int second{0};
};

//poor practice - returning a reference to a private data member
unsigned int& Time::badSetHour(int hh) {
    if(hh >= 0 && hh < 24) {
        hour = hh;
    } else {
        throw invalid_argument("house must be between 0-23");
    }
    return hour;
}

void Time::setHour(int h) {
    if((h>=0 && h < 24)) {
        this->hour = h;
    } else {
        throw invalid_argument("hour must be 0-23");
    }
}

void Time::setMinute(int m) {
    if((m>=0 && m < 60)) {
        minute = m;
    } else {
        throw invalid_argument("Out of bound minute");
    }
}

void Time::setSecond(int s) {
    if((s>=0 && s < 60)) {
        second = s;
    } else {
        throw invalid_argument("Out of bound minute");
    }
}

Time::Time(int hour, int minute, int second) {
    setTime(hour, minute, second);
}

void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

string Time::toUniversalString() const {
    ostringstream output;
    output << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << second;
    return output.str(); //return formatted string
}

string Time::toStandardString() const {
    ostringstream output;
    output << ((hour == 0 || hour == 12) ? 12 : hour%12) << ":" << setfill('0') << setw(2) << minute << ":" << setw(2)
        << second << (hour < 12 ? " AM" : " PM");
    return output.str();
}

void displayTime(const string& message, const Time& time) {
    cout << message << "\nUniversal time: " << time.toUniversalString()
        << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {
    Time t;
    displayTime("Initial time: ", t);
    t.setTime(13,27,6);
    displayTime("After setTime:", t);

    try {
        t.setTime(99, 99, 99);
    } catch(invalid_argument& ex) {
        cerr << "Exception: " << ex.what() << "\n\n";
    }
    displayTime("After attempting to set an invalid time: ", t);

    Time t1;
    Time t2{2};
    Time t3{21, 34};
    Time t4{12,25,42};

    cout << "Constructed with:\n\n";
    displayTime("t1: all arguments defaulted", t1);
    displayTime("t2: hour specified; minute and second defaulted", t2);
    displayTime("t3: hour and minute specified; second defaulted", t3);
    displayTime("t4: hour, minute and second specified", t4);

    try {
        Time t5{56,57, 99};
    } catch(invalid_argument& ex) {
        cerr << "Exception while initializing t5:" << ex.what() << endl;
    }

    /*

    */
    Time t6;
    unsigned int& hourRef = t6.badSetHour(20);
    cout << "Valid hour before modification: " << hourRef;
    hourRef = 30;
    cout << "\nInvalid hour after modification: " << t6.getHour();

    // Dangerous: Function call that returns                        
   // a reference can be used as an lvalue!                        
   t.badSetHour(12) = 74; // assign another invalid value to hour

   cout << "\n\n*************************************************\n"
      << "POOR PROGRAMMING PRACTICE!!!!!!!!\n"
      << "t.badSetHour(12) as an lvalue, invalid hour: "
      << t.getHour()
      << "\n*************************************************" << endl;
}


#endif