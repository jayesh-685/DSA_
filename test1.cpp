#include "bits/stdc++.h"
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
	    int n; 
	    cin >> n;
	    int x, y;
	    vector <int> xCordinates;
	    vector <int> yCordinates;
	    for (int i=0; i<n; i++) {
	        cin >> x >> y;
	        xCordinates.push_back(x);
	        yCordinates.push_back(y);
	    }
	    sort(xCordinates.begin(), xCordinates.end());
	    sort(yCordinates.begin(), yCordinates.end());
	    
	    auto it = unique(xCordinates.begin(), xCordinates.end());
	    xCordinates.resize(distance(xCordinates.begin(), it));
	    
	    it = unique(yCordinates.begin(), yCordinates.end());
	    yCordinates.resize(distance(yCordinates.begin(), it));
	    
	    cout << xCordinates.size() + yCordinates.size() << endl;
	}
	return 0;
}
