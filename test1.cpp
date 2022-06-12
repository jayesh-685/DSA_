#include "bits/stdc++.h"
using namespace std;


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		string a, b, c;
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a > b) 
			swap(a, b);
		

		// cout << a << " " << b << endl;

		while (a.length() && b.length()) {
			for (int i=0; i<k; i++) {
				if (i == 0) {
					c += a[0];
					a = a.substr(1);
					continue;
				}
				if (a[0] < b[0]) {
					c += a[0];
					a = a.substr(1);
				} else {
					break;
				}
				if (!a.length()) 
					break;
			}

			if (!a.length())
				break;

			for (int i=0; i<k; i++) {
				if (i == 0) {
					c += b[0];
					b = b.substr(1);
					continue;
				}
				if (b[0] < a[0]) {
					c += b[0];
					b = b.substr(1);
				} else {
					break;
				}
				if (!b.length())
					break;
			}

			if (!b.length())
				break;
		}

		cout << c << endl;
	}
}