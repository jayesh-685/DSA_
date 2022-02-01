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

struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
};


//Function to return the decoded string.

void huffmanDecode (struct MinHeapNode* root, string s, map <string, char> &m) {
    if (root->data != '$') {
        m.insert({s, root->data});
        return;
    }

	huffmanDecode(root->left, s+"0", m);
	huffmanDecode(root->right, s+"1", m);
}

string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    // Code here
    map <string, char> m;
    string s = "";
    huffmanDecode(root, s, m);

	string ans = "";
	int i = 0, n = binaryString.length();

	while (i < n) {
		string str = "";
		str += binaryString[i++];
		auto it = m.find(str);
		while (it == m.end()) {
			str += binaryString[i++];
			auto it = m.find(str);
		}
		ans += it->second;
	}

	return ans;

}



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    struct triplet {
        int val, weight;
        double vpw;
        triplet (int v, int w, double p) {
            val = v; weight = w; vpw = p;
        }
    };
    
    struct compare {
        bool operator () (triplet t1, triplet t2) {
            return t1.vpw > t2.vpw;
        } 
    };
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector <triplet> vec;
        
        for (int i=0; i<n; i++) {
            vec.push_back(triplet(arr[i].value, arr[i].weight, (double)(arr[i].value/arr[i].weight)));
        }
        
        sort(vec.begin(), vec.end(), compare());
        
        double ans = 0;
        int i=0;
        while (W && i<n) {
            if (vec[i].weight <= W) {
                W -= vec[i].weight;
                ans += vec[i].val;
                i++;
            } else {
                ans += (double)(vec[i].vpw * W);
                W = 0;
            }
        }
        
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends