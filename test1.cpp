#include "bits/stdc++.h"
using namespace std;

bool solve (vector <int> adj[], int v, int s) {
	bool visited [v+1];
	queue <int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int x: adj[curr]) {
			if (visited[x] && x!=curr)
				return true;
			else {
				visited[x] = true;
				q.push(x);
			}
		}
	}

	return false;
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