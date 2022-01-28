#include "bits/stdc++.h"
using namespace std;

int main () {
	long long n, m, a;
	cin >> n >> m >> a;

	long long p = max(n, m);
	long long q = min(n, m);
	long long x = ceil((double)p/a);
	if (q-a > 0)
		x += ceil((double)q/a);

	cout << x;
}