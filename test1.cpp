#include "bits/stdc++.h"
using namespace std;

string solve (int n) {
	string ans;
	string subStr;
	int x = n/3;
	if (n%3 == 0 || n%3 == 2) {
		subStr = "21";
	} else {
		subStr = "12";
	}

	for (int i=1; i<=x; i++) {
		ans += subStr;
	}

	if (n%3 == 2) {
		ans += '2';
	} else if (n%3 == 1) {
		ans += '1';
	}

	return ans;
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int n; 
		cin >> n;
		cout << solve(n) << endl;
	}
}