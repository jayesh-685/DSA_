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

pair<int, int> solve (string &s) {
	int operations = 0;
	while (true) {
		bool possible = false;
		for (int i=1; i<s.length(); i++) {
			if (isRegular(s.substr(0, i+1)) || isPanlindrome(s.substr(0, i+1))) {
				s = s.substr(i+1);
				operations++;
				possible = true;
				break;
			}
		}
		if (!possible)
			return {operations, s.length()};
	}

	return {-1, -1};
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		pair<int, int> ans = solve(s);
		cout << ans.first << " " << ans.second << endl;
	}
}