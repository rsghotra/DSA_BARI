#include<iostream>
using namespace std;

int length(char* input) {
    /* - careful this is very spohiticated
       - ARRAY INDEX USE PROBLEM
    INPUT:
        ARRAY:   | A | B | C | \0 |
              i->  0-->1-->2-->3.
            AT THIS TIME EVEN IF WE RETURN I it will be correct length becuase we gave 0th index 0th length during procesing but return time it will be increased to 1.
    //another question of USE OF ARRAY INDEX TO FIND OUT LENGTH

    //DOES NOT MATTER IF i GOES RIGHT ON TO NULL DELIM. AT THAT 
    length is Size-1 means not including null
    */
   int i = 0;
   for(i=0;input[i]!='\0';i++) {}
   return i;
}

int main() {
    char name[] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', '\0'};//automating heap memory allocation
    //power of string printing
    cout << "==>Input String: " << name << endl;
    cout << "==>Length of String is: " << length(name);
    return 0;
}