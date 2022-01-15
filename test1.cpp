// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find
// minimum number of nodes
int AVLnodes(int height)
{
	// Base Conditions
	if (height == 0)
		return 1;
	else if (height == 1)
		return 2;

	// Recursive function call
	// for the recurrence relation
	return (1 + AVLnodes(height - 1) + AVLnodes(height - 2));
}

// Driver Code
int main()
{
	int H = 5;
	cout << AVLnodes(H) << endl;
}
