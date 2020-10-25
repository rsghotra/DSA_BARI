#include<iostream>
using namespace std;

/*
*************LENGTH**********
*/

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

void _length() {
    char input[100];
    cout << "==>Input String: " << endl;
    cin.ignore();
    cin.getline(input, 100);
    cout << "==>Length of String is: " << length(input) << endl;
}

/*
*************MAX**********
*/

int max(int arr[], int n) {
    int m=0,i=0;
    for(i;i<n;i++) {
        if(arr[i]>m) m=arr[i];
    }
    return m;
}

/*
*************ANAGRAM**********
*/
void anagrams_iterative(const char* str1, const char* str2) {
    int i=0,j=0;
    for(i;str1[i]!='\0';i++){
        for(j;str2[j]!='\0';j++) {
            if(str1[i] == str2[j]) {
                break;
            }
        }
    }
    //||pitfall
    //Property of Anagrams that length must be same
    if(str1[i]=='\0'&&str2[j]=='\0') {
        cout << "Anagrams!" << endl;
        return;
    }
    cout << "Not Anagrams!" << endl;
}

void anagrams_hash(const char* str1, const char* str2) {
    //assuming all lower case letters
    //Must initialize the hash with 1;
    //remember we are going to decrement and increment hash numbers
    int i=0, hIndex=0;
    //chutiye it is an integer array mind boka hogaya hai 
    int H[26]={0};
    //Now What is going to happen is that There will be a REDUCE OPERATION. MAP ASCII 97-122 to HASH table with index 0-25
    //I am going to use formula; H[index_on_which_char_must save] = ASCII_CODE - BASE_ASCII_CODE_OF_SERIES (Assuming all lower case)
    for(i; str1[i]!='\0';i++) {
        //reduce operation;
        hIndex= str1[i] - 97;
        H[hIndex]+= 1;
    }
    i=0, hIndex=0;
    //Looking at second string nw
    for(i;str2[i]!='\0';i++) {
        //Reduce Operation again to find index;
        hIndex = str2[i] - 97;
        H[hIndex] = H[hIndex] - 1;
        if(H[hIndex] < 0) {
            cout << "Not Anagrams :(";
            return;
        }
    }
    //Case when there still a positive number in H. It happens when second string is smaller.
    if(max(H, 26)==0) {
        cout << "Anagrams :)";
        return;
    } else {
        cout << "Not Anagrams :(";
        return;
    }
}

void anagrams_bitset(const char* str1, const char* str2) {
    /*
        Most exciting topic. Check if two strings are anagrams, identify duplicates in a string are two most widely used questions.
        In this we create a Hash Table but in the form of 1 byte and then perform the bit operations.
        As we essentially want a particular bit is set or not. Therefore, we nust use Masing mechanism.
    */
   //1. initialize hash with zero
    int H = 0; //HASH  WE WILL USE
    int i = 0, a=0;
    for(i;str1[i]!='\0';i++) {
        a=1;
        //reduction to find the target index which we neec to set
        a = a << str1[i] - 97;
        //Merge operation does not require redue check as it will set the bit
        H = a | H;//MERGING
        //Now we need to perform Merging here in order to set he desired bit.
    }
    i = 0, a = 0;
    for(i; str2[i] != '\0'; i++) {
        a=1;
        a = a << str1[i] - 97;
        if(a & H == 0) {
            cout << "Not Anagrams." << endl;
            return;
        } else {
            //XOR: since there are no duplicates; Hence, we can again set the bit to 0 in case if one of the string is of different length.
            H = a ^ H;
        }
    }
    //we must check for the case when one of the string is of smaller length
    //Therefore, if everything went well then H must be back to zero position
    if(H==0) {
        cout << "Anagrams!" << endl;
    } else {
        cout << "Not Anagrams!"<<endl;
    }
}

void _areanagrams() {
    char inp1[100], inp2[100];
    cout <<"For Anagram Problem there exists three soultions as per below with its own limitations. Please choose 1 to continue."<<endl;
    int choice=0;
    do {
        cout << "1. Iterative Solution: O(n2); Picking one character and looking for it in second array. DO NOT HANDLE DUPLICATES OR EXTRA SPACE." << endl;
        cout << "2. Hash Table Solution: O(n), O(n): Creating a hash table of size 26 representing each alphabet. ASSUMING ALL LOWER CASE; HANDLE DUPLICATES & EXTRA SPACES" << endl;
        cout << "3. Bitset Operations: O(n): Assuming there are no duplicated as bit can only set either 0 or 1. Perfect weapon for detecting(not counting) duplicates or finding anagrams. DO NOT HANDLE DUPLICATES OR EXTA SPACES."<<endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
    } while(choice != -1 && choice != 1 && choice !=2&& choice !=3);
    
    cout <<"Program will prompt for two strings of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    cout <<"Please enter second string:=> ";
    cin.getline(inp2, 100);

    switch(choice) {
        case 1:
            anagrams_iterative(inp1, inp2);
            break;
        case 2:
            anagrams_hash(inp1, inp2);
            break;
        case 3:
            anagrams_bitset(inp1, inp2);
            break;
        case -1:
            cout << "Thank You"<<endl;
            break;
        default:
            break;
    }
}

/*
*************UPPERCASER**********
*/

void uppercaser(char str1[]) {
    int i=0;
    if(str1 == nullptr) return;
    cout << "Uppercaser(";
    cout << str1;
    cout <<")==>";
    //only touching lowercase letters and converting them to upppercase
    for(i;str1[i]!='\0';i++) {
        if(str1[i] >= 97 && str1[i] <= 122) {
            str1[i] = str1[i] - 32;
        }
    }
    cout << str1 << endl;
}

void _uppercaser() {
    char inp1[100];
    cout <<"For Uppercaser Problem there exists ONLY ONE EASY AND EFFICIENT solutions. USING ASCII MATH. Difference between upper and lower case letter in ascii code is 32"<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    uppercaser(inp1);
}

/*
*************LOWERCASER**********
*/

void lowercaser(char str1[]) {
    int i=0;
    if(str1 == nullptr) return;
    cout<<"Lowercaser(";
    cout<<str1;
    cout<<")==>";
    for(i;str1[i]!='\0';i++) {
        if(str1[i] >= 65 && str1[i] <= 90) {
            str1[i] = str1[i] + 32;
        }
    }
    cout << str1 << endl;
}

void _lowercaser() {
    char inp1[100];
    cout <<"For Lowercase Problem there exists ONLY ONE solution. USING ASCII MATH. Note: Difference between upper and lower case letter in ascii code is 32."<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    lowercaser(inp1);
}

/*
*************TOGGLECASER**********
*/

void togglecaser(char str1[]) {
    int i=0;
    cout << "Togglecaser(";
    cout<< str1;
    cout<<")==>";
    for(i;str1[i]!='\0';i++) {
        if(str1[i]>=65 && str1[i]<=90) {
            str1[i]=str1[i] + 32;
        } else if(str1[i] >=97 && str1[i]<=122) {
            str1[i]=str1[i] - 32;
        }
    }
    cout << str1 << endl;
}

void _togglecaser() {
    char inp1[100];
    cout <<"For Toggle Problem there exists ONLY ONE AND EFFICIENT solution. USING ASCII MATH. Note: Difference between upper and lower case letter in ascii code is 32."<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    togglecaser(inp1);
}

/*
*************VALIDATOR**********
*/
void validator(char* str1) {
    int i=0;
    cout << "Validator(";
    cout<< str1;
    cout<<")==>";
    for(i;str1[i]!='\0';i++) {
        if(!(str1[i]>=65 && str1[i]<=90) && (str1[i] >=97 && str1[i]<=122) && (str1[i]>= 48 && str1[i]<=57)) {
            cout << "InValid!"<<endl;
            return;
        }
    }
    cout << "Valid." << endl;
}

void _validator() {
    char inp1[100];
    cout <<"For Validator Problem there exists ONLY ONE AND EFFICIENT solution. USING ASCII CONDITIONALS ON RANGES."<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    validator(inp1);
}


int main() {
    int choice=0;
    do {
        cout<<"Welcome to Wonderwold of String. What would you like to do today?" << endl;
        cout << "1. Length: Gets You Length of string" << endl;
        cout << "2. Anagrams: Checks whether two strings are anagrams or not."<<endl;
        cout << "3. Uppercaser: Converts a given string to upper case USING ASCII MATH(str[i]-32)"<<endl;
        cout << "4. Lowercaser: Converts a given string to lower case USING ASCII MATH(str[i]+32)"<<endl;
        cout << "5. Togglecaser:Converts a given string to lower case USING ASCII MATH."<<endl;
        cout << "6. Validator: Validates if given input string only contains numbers and alphabets."<<endl;
        cout << "7. Reversor: Reverses the string in-place."<<endl;
        cout << "-1. To Exit." << endl;
        cin >> choice;
    } while(choice != -1 && choice >= 1 && choice <=2 && choice !=3 && choice !=4 && choice !=5 && choice !=6);

    switch(choice) {
        case 1:
            _length();
            break;
        case 2:
            _areanagrams();
            break;
        case 3:
            _uppercaser();
            break;
        case 4:
            _lowercaser();
            break;
        case 5:
            _togglecaser();
            break;
        case 6:
            _validator();
            break;
        case 7:
            _reversor();
            break;
        case 8:
            _comparator();
            break;
        // case 9:
        //     _duplicatehunter();
        //     break;
        // case 10:
        //     _vowelcalc();
        //     break;
        // case 11:
        //     _wordcalc();
        //     break;
        // case 12:
        // //palindrome and reverse are similar
        //     _ispalindrome();
        //     break;
        // case 13:
        //     _permutatestring();
        //     break;
        case -1:
            cout << "Thank You for Visiting the World of String! :)" << endl; 
    }
    return 0;
}