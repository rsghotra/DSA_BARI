#include<iostream>
using namespace std;

/*
*************LENGTH**********
*/

int length(const char* input) {
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
*************SWAP**********
*/
void swap(char* a, char* b) {
    char temp=*a;
    *a=*b;
    *b=temp;
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
        //reduction to find the target index which we neec to set.
        a = a << str1[i] - 97;
        //Merge operation does not require redue check as it will set the bit.
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
    //we must check for the case when one of the string is of smaller length.
    //Therefore, if everything went well then H must be back to zero position.
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

/*
*************REVERSOR**********
*/
void reversor(char* str1) {
    if(str1==nullptr) return;
    int i=0, j=length(str1) - 1;
    cout << "Reversor(";
    cout<< str1;
    cout<<")==>";
    for(i,j;i<j;i++,j--) {
        swap(&str1[i],&str1[j]);
    }
    cout << str1 << endl;
}

void _reversor() {
    char inp1[100], inp2[100];
    cout <<"For Reversor Problem there exists ONLY ONE AND EFFICIENT solution. IN-PLACE SWAP"<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    reversor(inp1);
}

/*
*************COMPAREROR**********
*/

int compareror(const char* str1, const char* str2) {
    int i=0, j=0;
    for(i,j; str1[i]!='\0' && str2[j]; i++, j++) {
        if(str1[i] != str2[j]) {
            break;
        }
    }
    //Must ensure the edge case is covered when one of the string is smaller than other.
    if(str1[i]=='\0' && str2[j] == '\0') {
        cout << "Same Strings!"<<endl;
        return 0;
    } else if(str1[i] < str2[j]) {
        cout <<"First string is samller than second string."<<endl;
        return -1;
    } else {
        cout <<"First string is larger than second string."<<endl;
        return 1;
    }
}

void _compareror() {
    char inp1[100], inp2[100];
    cout <<"For Compareror Problem there exists ONLY ONE AND EFFICIENT solution. Using Loops. Two strings must be of same lengths to be equal."<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    cout <<"Please enter second string:=> ";
    cin.getline(inp2, 100);
    compareror(inp1, inp2);
}

/*
*************ISPALINDROME**********
*/

void ispalindrome(const char* str1) {    
    int i=0, j=length(str1)-1;
    for(i,j; i<j; i++, j--) {
        if(str1[i] != str1[j]) {
            cout << "Not Palindrome."<<endl;
            return;
        }
    }
    cout << "Palindrome." << endl;
}

void _ispalindrome() {
    char inp1[100];
    cout <<"Palindrome Problem IS EXACTLY SAME AS REVERSING ARRAY IN PLACE. YOU CHECK FROM BOTH ENDS IF CHARS ARE SAME. INSTEAD OF SWAP. WE CHECK."<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    ispalindrome(inp1);
}

/*
*************VOWELCALC**********
*/

void vowelcalc(const char* str1) {
    int vowels=0,consonants=0,i=0;
    //check for vowel
    for(i;str1[i]!='\0';i++) {
        if(str1[i] == 65 || str1[i] == 97 || str1[i] == 'E' || str1[i]=='e' || str1[i] == 'I' || str1[i]=='i' ||
         str1[i] == 'O' || str1[i]=='o'|| str1[i] == 'U' || str1[i]=='u') {
             vowels++;
         } else if((str1[i] >= 65 && str1[i] <=90) || (str1[i] >= 97 && str1[i] <= 122)) {
             consonants++;
         }
    }
    cout << "Total Vowels Found: " << vowels << endl;
    cout << "Total Consonants Found: " << consonants << endl;
}

void _vowelcalc() {
    char inp1[100];
    cout <<"Vowel & Consonants Calculator Problem IS BEST solved using ASCII character code check."<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    vowelcalc(inp1);
}

/*
*************WORDCALC**********
*/

void wordcalc(const char* str1) {
    int spaces=0, i=0;
    for(i;str1[i]!='\0';i++) {
        //checking if incoming character is a space and ALSO previous visited character was not space as well to avoid duplicate space detection.
        if(str1[i]==' ' && str1[i-1]!=' ') {
            spaces++;
        }
    }
    //By the formula - number of words must be space+1
    cout << "Number of words in given string is: " << spaces+1 << endl;
}

void _wordcalc() {
    char inp1[100];
    cout <<"WORD CALCULATOR Problem IS BEST solved SPACE+1 startegy. In each properly structured if there are S spaces then number of words are S+1;"<<endl;
    cout <<"Program will prompt for input string of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);
    wordcalc(inp1);
}

/*
*************DUPLICATE CHARACTER FINDER AND COUNTER**********
*/

void duplicatehunter_hash(const char* str1) {
    int i=0;
    //assuming only lowecase character;  Miust initialize HASH to zero
    int H[26] = {0};
    //first fill the hash
    for(i;str1[i]!='\0';i++) {
        //REDUCE OPERAION WILL TAKE PLACE
        H[str1[i]-97]++;
    }
    //Traversing HASH and going over finding duplicates and its counts
    i=0;
    for(i;i<26;i++) {
        if(H[i] > 1) {
            cout << "Character " << char(i+97)<< " is occuring " << H[i] << " times.";
        }
    }
    cout << endl;
}

void duplicatehunter_bitset(const char* str1) {
    cout << "Duplicates: ";
    int i=0;
    /*assuming lower case characters.
        NO REDUCE Operation will take place here. INSTEAD WE WILL USE LEFT SHIFT
        Trace the character and decide on which index the bit must be SET(MERGER|OR)
    */
   //SHOOT: PIT FALL. INITIALIZE THE HASH WITH ZERO
    int H=0;
    int a=0;
    //filling the HASH or setting the bit will be done by merging
    for(i;str1[i]!='\0';i++) {
        a=1;
        //perform left shit to as many indexes
        a = a << str1[i] - 97;
        /*
            Here we will first need to CHECK if the BIT IS ALREADY SET OR NOT BY PERFORMING MASKING
            IF IT IS SET THEN CHARACTER IS DUPLICATE
        */
       //SHOOT: PIT FALL: & has lower precedence than >
       if((a&H) > 0) {
           cout << str1[i] << " ";
       } else {
           //perform ORING to set the bit
            H = a | H;
       }
    }
}

void _duplicatehunter() {
    char inp1[100];
    cout <<"For Duplicate Character Problems- ASSUMING ALL LOWER SIZE CHARACTER. There exists three soultions but we are NOT implementing iterative."<<endl;
    int choice=0;
    do {
        cout << "1. Hash Table Solution: O(n), O(n): Creating a hash table of size 26 representing each alphabet. ASSUMING ALL LOWER CASE; HANDLE DUPLICATES & EXTRA SPACES" << endl;
        cout << "2. BitSet Duplicate Finder: Classic use of bitwise operations. Assuming incoming string is lower characters." << endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
    } while(choice != -1 && choice != 1 && choice !=2);
    
    cout <<"Program will prompt for two strings of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);

    switch(choice) {
        case 1:
            duplicatehunter_hash(inp1);
            break;
        case 2:
            duplicatehunter_bitset(inp1);
            break;
        case -1:
            cout << "Thank You"<<endl;
            break;
        default:
            break;
    }
}

/*
*************STRING PERMUTATOR**********
*/

void stringpermutator_backtracking(char S[], int k) {
    static int A[4];
    static char Result[4];
    int i=0;
    if(S[k]=='\0') {
        Result[k]='\0';
        cout << Result << " ";
    } 
    else {
        for(i;S[i]!='\0';i++) {
            if(A[i]==0) { //element unseen
                Result[k] = S[i];
                A[i]=1;
                stringpermutator_backtracking(S, k+1);
                A[i]=0;
            }
        }
    }
}

void stringpermutator_swap(char S[], int l, int h) {
    int i;
    if(l==h) {
        cout << S << " ";
    } else {
        for(i=l;i<=h;i++) {
            swap(S[l], S[i]);
            stringpermutator_swap(S, l+1, h);
            swap(S[l], S[i]);
        }
    }
}

void _permutatestring() {
    char inp1[100];
    cout <<"String Permutation Problem- There exists seven soultions. Each will be implemented as the course progresses."<<endl;
    int choice=0;
    do {
        cout << "1. Using Swapping Elements" << endl;
        cout << "2. BackTracking" << endl;
        cout << "3. Using Sorting" << endl;
        cout << "4. Using Hashmap" << endl;
        cout << "5. Using Arrays" << endl;
        cout << "6. Using Sliding Window" << endl;
        cout << "-1. Exit." << endl;
        cin >> choice;
    } while(choice != -1 && choice != 1 && choice !=2);
    
    cout <<"Program will prompt for a strings of max length of 99."<<endl;
    cout <<"Please enter first  string:=> ";
    cin.ignore();
    cin.getline(inp1, 100);

    switch(choice) {
        case 1:
            stringpermutator_swap(inp1, 0, length(inp1)-1);
            break;
        case 2:
            stringpermutator_backtracking(inp1, 0);
            break;
        case -1:
            cout << "Thank You"<<endl;
            break;
        default:
            break;
    }
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
        cout << "8. Compareror: Compares two string and tells if first is equal, less or greater than the second string."<<endl;
        cout << "9. Palindrome: Analyze given string and tells if it a palindrome or not."<<endl;
        cout << "10.Vowel&Consonants Calculator:Tells given string is consists of how many vowels and how many consonants."<<endl;
        cout << "11.Word Calculator:Tells how many words the given string consists of."<<endl;
        cout << "12.Duplicate Finder & Counter: Using HASH TABLE OR BITSET - WE SOLVE THIS PROBLEM NICELY"<<endl;
        cout << "13.Permutator: Prints permutations of given string. MANY SOLUTIONS."<<endl;
        cout << "-1. To Exit." << endl;
        cin >> choice;
    } while(choice != -1 && !(choice >= 1 && choice <=13));

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
            _compareror();
            break;
        case 9:
            _ispalindrome();
            break;
        case 10:
            _vowelcalc();
            break;
        case 11:
            _wordcalc();
            break;
        case 12:
            _duplicatehunter();
            break;
        case 13:
            _permutatestring();
            break;
        case -1:
            cout << "Thank You for Visiting the World of String! :)" << endl; 
    }
    return 0;
}

void Perm(char S[], int k) {
    static int visited[10]{0};
    static char result[10]{};

    if(S[k] == '\0') {
        result[k] = '\0';
        cout << result << endl;
    } else {
        for(int i = 0; S[i] != '\0'; i++) {
            if(visited[i] == 0) {
                result[k] = S[i];
                visited[i] = 1;
                Perm(S, k+1);
                visited[i] = 0;
            }
        }
    }
}