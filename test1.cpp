#include "bits/stdc++.h"
using namespace std;

int main () {
	int T;
	cin >> T;
	while (T--) {
		int l, r, a;
		cin >> l >> r >> a;
		int res = 0;
		if (l/a == r/a) {
			res = (r/a) + (r%a);
		} else {
			res = max((r/a + r%a), (r/a -1 + a-1));
		}

		cout << res << endl;	
	}
	
}