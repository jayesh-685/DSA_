#include "bits/stdc++.h"
using namespace std;


int main () {
	int T;
	cin >> T;
	while (T--) {
		int n; 
		cin >> n;
		vector <int> v (n);
		for (int i=0; i<n; i++)
			cin >> v[i];
		
		sort(v.begin(), v.end());
		
		int prefix = v[0], suffix = 0;
		int i=1, j=n-1;
		bool flag = false;
		while (i<j) {
			if (prefix < suffix) {
				flag = true;
				break;
			} else {
				prefix += v[i];
				suffix += v[j];
				i++;
				j--;
			}
		}

		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}