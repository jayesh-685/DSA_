#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // -1 -> camera required
    // 0 -> has camera
    // 1 -> covered
    
    int solve (TreeNode* root, int &count) {
        if (root == NULL)
            return 1;
        
        int ln = solve(root->left, count);
        int rn = solve(root->right, count);
        
        if (ln==-1 || rn==-1) {
            count++;
            return 0;
        }
        
        if (ln==0 || rn==0) {
            return 1;
        }
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        static int count = 0;
        int val = solve(root, count);
        if (val==-1)
            return count+1;
        return count;
    }
};

int main () {

}