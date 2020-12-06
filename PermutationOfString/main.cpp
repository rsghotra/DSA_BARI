#include<iostream>
using namespace std;


void perm(char S[], int k) {
    //must initialized with zero
    // i tracks input and visited
    // k tracks result and have co-relation with input array
    static int visited[10]{0};
    static char result[10];

    if(S[k] == '\0') {
        result[k] = '\0';
        cout << result << endl;
        return;
    } else {
        for(int i = 0; S[i] != '\0'; ++i) {
            if(visited[i] == 0) {
                //pick up character
                result[k] = S[i];
                visited[i] = 1;
                perm(S, k+1);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    char S[] = "RANVEER";

    perm(S, 0);
}