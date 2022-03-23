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
		if (n%2 == 0)
			cout << n/2 << endl;
		else {
			n /= 2;
			n += 1;
			n *= -1;
			cout << n << endl;
		}
	}
}