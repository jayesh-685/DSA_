#include "bits/stdc++.h"
using namespace std;

int largestWordInSentence (char arr[], int n) {
    int maxLength = 0, currLength = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == ' ')
            currLength = 0;
        else
            currLength++;
        maxLength = max(maxLength, currLength);
    }
    return maxLength;
}

int main () {
    int n;
    cin >> n;
    cin.ignore();   // to flush out any buffer
    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();
    cout << largestWordInSentence(arr, n);

    return 0;
}