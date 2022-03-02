#include "bits/stdc++.h"
using namespace std;

int main () {
	int x, y;
	int a;
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			cin >> a;
			if (a) {
				x=i; y=j;
			}
		}
	}

	cout << abs(x-2) + abs(y-2);
}