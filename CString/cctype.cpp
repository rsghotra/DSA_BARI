/*
    C-String Related Manipulation:

    1. Character Manipuation and Test - cctype
        - isdigit(), isalpha(), isalnum(), ispunct(), isspace(), islower, isupper, tolower, toupper, iscntrl, isgraph, isprint
*/

#include<iostream>
#include<cctype>
using namespace std;

int main() {
    cout << "According to isdigit:\n"
        << (isdigit('8') ? "8 is a" : "8 is not a") << " digit\n"
        << (isdigit('#') ? "# is a" : "# is not a") << " digit\n";

    cout << "\nAccording to isalpha:\n"
      << (isalpha('A') ? "A is a" : "A is not a") << " letter\n"
      << (isalpha('b') ? "b is a" : "b is not a") << " letter\n"
      << (isalpha('&') ? "& is a" : "& is not a") << " letter\n"
      << (isalpha('4') ? "4 is a" : "4 is not a") << " letter\n";

    cout << "\nAccording to isalnum:\n"
      << (isalnum('A') ? "A is a" : "A is not a") 
      << " digit or a letter\n"
      << (isalnum('8') ? "8 is a" : "8 is not a")
      << " digit or a letter\n"
      << (isalnum('#') ? "# is a" : "# is not a")
      << " digit or a letter\n";
    
    cout << "\nAccording to isxdigit:\n"
      << (isxdigit('F') ? "F is a" : "F is not a")
      << " hexadecimal digit\n"
      << (isxdigit('J') ? "J is a" : "J is not a")
      << " hexadecimal digit\n"
      << (isxdigit('7') ? "7 is a" : "7 is not a")
      << " hexadecimal digit\n"
      << (isxdigit('$') ? "$ is a" : "$ is not a")
      << " hexadecimal digit\n"
      << (isxdigit('f') ? "f is a" : "f is not a")
      << " hexadecimal digit" << endl;
    
    cout << "According to islower:\n"
      << (islower('p') ? "p is a" : "p is not a") 
      << " lowercase letter\n"
      << (islower('P') ? "P is a" : "P is not a") 
      << " lowercase letter\n"
      << (islower('5') ? "5 is a" : "5 is not a") 
      << " lowercase letter\n"
      << (islower('!') ? "! is a" : "! is not a") 
      << " lowercase letter\n";

   cout << "\nAccording to isupper:\n"
      << (isupper('D') ? "D is an" : "D is not an") 
      << " uppercase letter\n"
      << (isupper('d') ? "d is an" : "d is not an") 
      << " uppercase letter\n"
      << (isupper('8') ? "8 is an" : "8 is not an") 
      << " uppercase letter\n"
      << (isupper('$') ? "$ is an" : "$ is not an") 
      << " uppercase letter\n";

    
    //characters are handled in integer format always remmember
    cout <<"\nu converted to uppercase is "
        << static_cast<char>(toupper('u'))
        << "\n7 converted to uppercase is "
        << static_cast<char>(toupper('7')) << endl;
}