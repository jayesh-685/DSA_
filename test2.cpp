#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node* node)
{
    vector <vector <int>> ans;
    
}