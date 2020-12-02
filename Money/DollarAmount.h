#ifndef DOLLAR_H
#define DOLLAR_H
#include<string>
#include<sstream>
#include<cmath>
#include<cstdint>

class DollarAmount {
private:
    int64_t amount{0}; //dollar amount in pennies
public:
    explicit DollarAmount(int64_t value) : amount{value}{}

    void add(DollarAmount right) {
        amount += right.amount;
    }

    void subtract(DollarAmount right) {
        amount -= right.amount;
    }
    //return a string representation of dollar amount object
    std::string toString() const {
        std::string dollars{std::to_string(amount/100)};
        std::string cents{std::to_string(std::abs(amount % 100))};
        std::ostringstream output;
        output << dollars << "." << (cents.size() == 1 ? "0":"") << cents;
        return output.str();
    }

    void addInterest(int rate, int divisor) {
        //calculate interest using addition operation
        DollarAmount interest{(amount*rate + divisor/2)/divisor};
        add(interest);
    }
};

#endif
