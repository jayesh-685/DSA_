#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

	bool dfs (vector <int> adj[], vector <bool> &visited, vector <bool> &currStack, int source) {
		visited[source] = true;
		currStack[source] = true;

		for (int x: adj[source]) {
			if (!visited[x] && dfs(adj, visited, currStack, x))
				return true;
			else if (currStack[x])
				return true;
		}

		currStack[source] = false;
		return false;
	}

	bool detectLoop (vector <int> adj [], int n) {
		vector <bool> visited (n);

		for (int i=0; i<n; i++) {
			if (!visited[i]) {
				vector <bool> currStack (n);
				if (dfs(adj, visited, currStack, i)) {
					return true;
				}
			}
		}

		return false;
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses];
		for (int i=0; i<numCourses; i++) {
			adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}

    }
};

int main () {

}