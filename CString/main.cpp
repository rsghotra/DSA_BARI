#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int main() {
    char s1[17]{};

    char s2[]{"Copy this string"};

    memcpy(s1, s2, 17);
    cout << "After s2 is copied into s1 with memcpy,\n"
     << "s1 contains \"" << s1  << '\"' << endl;

     char x[]{"Home Sweet Home"};

     cout << "The string in array x before memmove is: " << x;
     cout << "\nThe string in array x after memmove is: "
        << static_cast<char*>(memmove(x, &x[5], 10)) << endl;

    char s3[]{"ABCDEFG"};
    char s4[]{"ABCDXYZ"};

    cout << "s1 = " << s1 << "\ns2 = " << s2 << endl
        << "\nmemcmp(s1,s2,4)= " << setw(3) << memcmp(s3, s4, 4)
        << "\nmemcmp(s1,s2,7)= " << setw(3) << memcmp(s3, s4, 7)
        << "\nmemcmp(s2,s1,7)= " << setw(3) << memcmp(s4, s3, 7)
        << endl;
    
    char s[]{"This is a string"};
    cout << static_cast<char*>(memchr(s, 'r', 16)) << endl;

    char string1[25]{"BBBBBBBBBBBBBBBB"};
    cout << static_cast<char*>(memset(string1, 'b', 7)) << endl;
}