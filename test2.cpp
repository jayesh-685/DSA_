#include "bits/stdc++.h"
using namespace std;

bool isRegular (string s) {
	stack <int> st;
	for (int i=0; i<s.length(); i++) {
		if (s[i] == '(') {
			st.push(1);
		} else {
			if (st.empty())
				return false;
			st.pop();
		}
	}
	return st.empty();
}

bool isPanlindrome (string s) {
	int n = s.length();
	for (int i=0; i<s.length()/2; i++) {
		if (s[i] != s[n-i-1])
			return false;
	}

	return true;
}

int main () {
    string s = "abcdef";
    s = s.substr(1);
    cout << s << endl;

    cout << isRegular("(())(())") << endl;
    cout << isRegular(")(") << endl;
    cout << isRegular(")()()))()") << endl;

    cout << isPanlindrome("())(") << endl;
    cout << isPanlindrome("((((") << endl;
    cout << isPanlindrome(")(()()((()()") << endl;
}