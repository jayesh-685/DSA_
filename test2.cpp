#include "bits/stdc++.h"
using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string ans = "YES";
		vector <int> v1, v2;
		int x;
		for (int i=0; i<n; i++) {
			cin >> x;
			v1.push_back(x);
		}
		for (int i=0; i<n; i++) {
			cin >> x;
			v2.push_back(x);
		}

		// finding diff
		int diff;
		bool flag = false;
		for (int i=0; i<n; i++) {
			if (v1[i] && v2[i]) {
				diff = v1[i] - v2[i];
				flag = true;
				break;
			}
		}
		if (!flag)
			diff = v1[0] - v2[0];

		if (diff < 0)
			ans = "NO";
		
		else {
			for (int i=0; i<n; i++) {
				int val = v1[i] - v2[i];
				if (val != diff) {
					if (val < diff && v2[i] == 0)
						continue;
					else {
						ans = "NO";
						break;
					}
				}
			}
		}

		cout << ans << endl;
	}
}