#include "bits/stdc++.h"
using namespace std;

int solve (string s) {

}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int op=0, i=0;
		for (int j=1; j<n; j++) {
			if ((s[i]=='(' && s[j]==')') || (s[i] == s[j])) {
				i = ++j;
				++op;
			}
		}
		cout << op << " " << n-i << endl;
	}
	
}