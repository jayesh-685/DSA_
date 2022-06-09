#include "bits/stdc++.h"
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
	vector <int> ans;
	int i = 1;
    int n = numbers.size();
	while (i<n && numbers[i]+numbers[i-1] < target)
		i++;

	if (numbers[i] + numbers[i-1] == target) {
		ans.push_back(i);
		ans.push_back(i+1);
		return ans;
	}

	int l=i-1, r=i;
	while (l>0 && r<n) {
		int sum = numbers[l]+numbers[r];
		if (sum == target) {
			break;
		} else if (sum > target) {
			l--;
		} else {
			r++;
		}
	}

	ans.push_back(l+1);
	ans.push_back(r+1);
	return ans;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
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

		bool flag = false;
		int maxDiff = 0;

		for (int i=0; i<n; i++) {
			if (v1[i] < v2[i]) {
				flag = true;
				break;
			}
			maxDiff = max(maxDiff, abs(v1[i]-v2[i]));
		}

		for (int i=0; i<n; i++) {
			int val = max(v1[i]-maxDiff, 0);
			if (val != v2[i]) {
				flag = true;
				break;
			}
		}

		if (flag == true) 
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}
}