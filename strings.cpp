#include "bits/stdc++.h"
using namespace std;

void toUpperCase (string &s) {
    for (int i=0; i<s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    }

    // or use transform(s.begin(), s.end(), s.begin(), ::toupper);
    
}

void toLowerCase (string &s) {
    for (int i=0; i<s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }

    // or use transform(s.begin(), s.end(), s.begin(), ::tolower);
}

int maxFreqChar (const string &s) {
    int freqArr [26] = {0};
    
    for (int i=0; i<s.length(); i++) 
        freqArr[s[i]-'a']++;

    int maxFreq = INT_MIN;

    for (int i=0; i<26; i++)
        if (freqArr[i] > maxFreq)
            maxFreq = freqArr[i];

    return maxFreq;
}

int main () {
    string s;
    getline(cin, s);
    cout << maxFreqChar(s) << endl;
    //cout << s << endl;

}