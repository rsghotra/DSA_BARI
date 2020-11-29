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
        void setTime(int, int, int);
        std::string toUniversalString() const;
        std::string toStandardString() const;
    private:
        unsigned int hour{0};
        unsigned int minute{0};
        unsigned int second{0};
};

void Time::setTime(int h, int m, int s) {
    if((h >=0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        minute = m;
        second = s;
    } else {
        throw invalid_argument("Out of bound");
    }
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
}


#endif