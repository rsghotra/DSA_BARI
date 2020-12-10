#include<iostream>
#include<string>
#include<array>
#include<unordered_set>
using namespace std;

#include<unordered_set>
#include<iostream>
#include<cctype>
#include<string>
#include<stdexcept>
#include<iterator>
#include<vector>
using namespace std;
class Solution {
public:
    string getMorseCode(int) const;
    string transform(const string&) const;
    int uniqueMorseRepresentations(vector<string>& words);
};

string Solution::getMorseCode(int c) const {
    array<string, 26> morseCodes{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.",                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    try {
        return morseCodes.at(c-97);

    } catch(out_of_range& ex) {
        cout << "Out of bound index supplied to the function: " << ex.what() << endl;
        return "";
    }
}

string Solution::transform(const string& word) const {
    string transformed{""};
    string::const_iterator iter{word.begin()};
    
    while(iter != word.end()) {
        transformed.append(getMorseCode(*iter));
        ++iter;
    }
    return transformed;
}

int Solution::uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> result;

    for(const string& word: words) {
        result.emplace(transform(word));
    }
    return result.size();
}


int main() {
    // unordered_set<string> myset{"yellow", "green", "blue"};
    // array<string, 2> myArray{"black", "white"};
    // string mystring = "red";

    // myset.emplace(mystring);
    // myset.emplace(mystring+"dish");
    // myset.emplace("yellow");
    // myset.erase("yellow");
    // cout << "myset contains: ";
    // for(const string& x: myset) {
    //     cout << x << " ";
    // }

    // unordered_set<int> uset = {4,1,2,3,4,2,3};

    // auto search = uset.find(2);

    // if(search != uset.end()) {
    //     cout << "\nFound " << (*search) << "\n";
    // }

    // for(const auto& ele: uset) {
    //     cout << ele << " ";
    // }
    // cout << endl;

    vector<string> words{"gin", "zen", "gig", "msg"};
    Solution sol;
    cout << sol.uniqueMorseRepresentations(words) << endl;
}