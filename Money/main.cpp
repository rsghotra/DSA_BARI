#include "DollarAmount.h"
#include<iomanip>
#include<iostream>
using namespace std;
int main() {
    DollarAmount d1{12345};
    DollarAmount d2{1576}; //$15.76

    cout << "After adding d2 (" << d2.toString() << ") into d1 (" << d1.toString() << "), d1 = ";
    d1.add(d2);
    cout << d1.toString() << "\n\n";

    cout << "After substracting d2 (" << d2.toString() << ") into d1 (" << d1.toString() << "), d1 = ";
    d1.subtract(d2);
    cout << d1.toString() << "\n\n";

    cout << "After subtracting d1 (" << d1.toString() << ") from d2 ("
      << d2.toString() << "), d2 = ";
    d2.subtract(d1); // modifies object d2
    cout << d2.toString() << "\n\n";

    cout << "Enter integer interest rate and divisor. For example:\n" 
      << "for     2%, enter:    2 100\n" 
      << "for   2.3%, enter:   23 1000\n"
      << "for  2.37%, enter:  237 10000\n"
      << "for 2.375%, enter: 2375 100000\n> ";
    int rate;
    int divisor;
    cin >> rate >> divisor;
    int bal;
    cout << "Enter Initial Balance" << setw(3);
    cin >> bal;
    DollarAmount balance{bal};
    cout << "\nInitial balance: " << balance.toString() << endl;

     cout << "\nYear" <<setw(20) << "Amount on deposit" << endl;

    for(unsigned int year{1}; year <= 20; year++) {
        balance.addInterest(rate, divisor);

        cout << setw(4) << year << setw(40) << balance.toString() << endl;
    }

    return 0;
}