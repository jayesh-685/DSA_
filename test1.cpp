#include "bits/stdc++.h"
using namespace std;

bool utility (vector<vector<int>> &grid, int i, int j, vector <vector <bool>> &visited 	) {
	
	if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0)
		return false;
	
	if (grid[i][j] == 2)
		return true;

	visited[i][j] = true;
	
	if (utility(grid, i, j-1, visited) || utility(grid, i-1, j, visited) || utility(grid, i, j+1, visited) || utility(grid, i+1, j, visited))
		return true;
		
	else
		return false;
}

bool is_Possible(vector<vector<int>>& grid) 
{
	//code here
	int r = grid.size();
	int c = grid[0].size();
	vector <vector <bool>> visited (r, vector<bool>(c, false));
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (grid[i][j] == 1) {
				return utility(grid, i, j, visited);
			}
		}
	}
}