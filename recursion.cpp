#include "bits/stdc++.h"
using namespace std;

int fibonaci (int n) {
    if (n == 0 || n == 1)
        return n; 
    return fibonaci(n-1) + fibonaci(n-2);
}

int sum (int n) {
    // return sum till n
    if (n == 0)
        return 0;
    return n + sum(n-1);
}

int power (int a, int n) {
    if (n == 0)
        return 1;
    return a*power(a, n-1);
}

int factorial (int n) {
    if (n == 0)
        return 1;
    return n*factorial(n-1);
}

bool checkSorted (int arr[], int n) {
    // check if the array is sorted using recursion (both increasing and strictly increasing)
    if (n == 1)
        return true;
    return (arr[1] >= arr[0] && checkSorted(arr+1, n-1));
}

void printNoDec (int n) {
    if (n == 0)
        return;
    cout << n << " ";
    printNoDec(n-1);
}

// my approach
/* void printNoInc (int i, int n) {
    if (i > n)
        return;
    cout << i << " ";
    printNoInc(++i, n);
} */

// better approach
void printNoInc (int n) {
    if (n == 0)
        return;
    printNoInc(n-1);
    cout << n << " ";

    // here we will keep on calling till we reach 1 and then start printing unlike prev function where we printed first and then called next function
}

int firstOccurance (int arr[], int n, int k, int i) {
    // find the first occurance of an element in an array
    if (i == n) 
        return -1;
    if (arr[i] == k)
        return i;
    return firstOccurance(arr, n, k, i+1);
}

/* int lastOccurance (int arr[], int n, int k, int i) {
    // basically we go to the end of the array using recusrsion and then keep on returning -1 till key is not found and when key is found we keep on returning index using an if statement
    if (i == n)
        return -1;
    int answer = lastOccurance(arr, n, k, i+1);
    if (answer != -1)
        return answer;
    if (arr[i] == k)
        return i;
    return -1;
} */

int lastOccurance (int arr[], int n, int k, int i) {
    // same as firstOccurance except we start from last  // better than prev approach
    // i is n-1
    if (i == 0)
        return -1;
    else if (arr[i] == k)
        return i;
    else 
        return lastOccurance(arr, n, k, i-1);
}

/* int lastOccurance (int arr[],int n,int t) {
    if (arr[n-1]==t) {
        return n-1;
    }
    return lastOccurance(arr,n-1,t);
} */

void reverse (const string &str) {
    // we will go to the last of the string then just print each character from the last. We won't be reversin the original string
    if (str.length() == 0)
        return;
    string rest = str.substr(1);  // will make a substring starting from index 1
    reverse(rest);
    cout << str[0]; 
}

void reverse (string &str, int i, int n) {
    if (i > n-1)
        return;
    char temp = str[i];
    str[i] = str[n-1];
    str[n-1] = temp;
    reverse(str, i+1, n-1);
}

void replacePi (const string &s) {
    if (s.length() == 0)
        return;
    if (s[0] == 'p' && s[1] == 'i') {
        cout << "3.14";
        replacePi(s.substr(2));
    } else {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

void towerOfHanoi (int n, char A, char B, char C) {
    // we have to move n discs from A (source) to C (dest) using C (help). For that we move the top n-1 discs from src to help using dest as helping rod and then move the nth disc (biggest one) from source to dest using helping rod and then move the other n-1 discs to dest using using src as help
    if (n == 1) {
        cout << "Move 1 from " << A << " to " << C << endl; 
        return;
    }
    towerOfHanoi(n-1, A, C, B);
    cout << "Move " << n << " from " << A << " to " << C << endl;
    towerOfHanoi(n-1, B, A, C);
}

// my way
/* void removeDuplicates (const string &s) {
    // if s = "aaaaabbbbccchhhh" then print/return abch 
    if (s.length() == 0)
        return;
    if (s[0] != s[1])
        cout << s[0];
    removeDuplicates(s.substr(1));
    
} */

// we will send the whole string except the first character to the recursive function assuming that the function will return the string removing all duplicates then we will compare the first char to the first character of the returned string and if they are equal then we will only return the returned string otherwise we will return char + returned string
string removeDuplicates (const string &s) {
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = removeDuplicates(s.substr(1));   // will go to the last of substr then remove duplicates
    if (ans[0] == ch)
        return ans;
    return ch+ans;
}

string moveXtoLast (const string &s) {
    // we will be given a string and we have to move all the x in it to last position.
    // similar thought process like the last question we will compare first char and the remaining string and if first char is x we will add it to last and return
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = moveXtoLast(s.substr(1));
    if (ch == 'x')
        return ans + ch;
    return ch + ans;
}

void subStrings (string s, string ans) {
    // here s is our string and ans is ""
    // we have to write all substrings using recursion. Basically we start with an empty string and at each step we have two steps either to add a char or to not till we run out of characters in original string. 
    // Ex we have "" and string is "ABC" then at first step we can add "A" or not then at next step we can add "B" to "A" or not and add "B" to "" or not then at final step we can add or not add "C" to "AB", "A", "B", "" resulting in 8 sub strings
    if (s.length() == 0) {
        cout << ans << endl;
        return;
    }
    subStrings(s.substr(1), ans);  // not add
    subStrings(s.substr(1), ans+s[0]);    // add

}

void subStringAscii (string s, string ans) {
    // similar to prev ques but here we have to add or not add ascii value of char we are adding or not adding so we will just call it 3 times
    if (s.length() == 0) {
        cout << ans << endl;
        return;
    }
    subStringAscii(s.substr(1), ans);  // not add
    subStringAscii(s.substr(1), ans + s[0]);    // add
    subStringAscii(s.substr(1), ans + to_string((int)s[0]));        
}

int main () {
    //cout << fibonaci(5) << endl;
    // cout << sum(4) << endl;
    //cout << power(2, 5) << endl;
    //cout << factorial(5) << endl;
    // int arr[] = {1, 2, 2, 4, 5};
    // cout << checkSorted(arr, 5) << endl;
    //printNoDec(9);
    //printNoInc(9);
    //int arr[] = {1, 2, 3, 2, 5, 2, 3};
    //cout << firstOccurance(arr, 7, 2, 0) << endl;
    //cout << lastOccurance(arr, 7, 2, 6) << endl;
    // string s;
    // getline(cin, s);
    // reverse(s, 0, s.length());
    // cout << s << endl;
    //replacePi(s);
    towerOfHanoi(3, 'A', 'B', 'C');
    //cout << moveXtoLast(s) << endl;
    //string s, ans = "";
    //cin >> s;
    //subStringAscii(s, ans);

}
