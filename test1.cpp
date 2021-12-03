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

void levelOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->val << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
} 


// TreeNode* insertBST_I (TreeNode* root, int x) {
//     TreeNode* temp = new TreeNode (x);

//     TreeNode* curr = root;
//     TreeNode* parent = curr;

//     while (curr != NULL) {
//         parent = curr;
//         if (x > curr->val)
//             curr = curr->right;
//         else if (x < curr->val)
//             curr = curr->left;
//         else
//             return root;    // because element is already present
//     }
//     if (parent == NULL)
//         return temp;
//     else if (x > parent->val)
//         parent->right = temp;
//     else
//         parent->left = temp;
//     return root;
// }


bool checkValid (int currLevel, vector <int> &v) {
    bool ans = true;
    if (currLevel%2 == 0) {
        for (int i=0; i<v.size()-1; i++) {
            if (v[i]%2 == 0)
                return false;
            if (v[i] >= v[i+1])
                return false;
        }
        if (v[v.size()-1]%2 == 0)
            return false;
        return true;
    } else {
        for (int i=0; i<v.size()-1; i++) {
            if (v[i]%2 == 1)
                return false;
            if (v[i] <= v[i+1])
                return false;
        }
        if (v[v.size()-1]%2 == 1)
            return false;
        return true;
    }
}
bool isEvenOddTree(TreeNode* root) {
    if (root == NULL)
        return true;
    bool ans = true;
    int currLevel = 0;
    queue <TreeNode*> q;
    q.push(root);
    while (ans && !q.empty()) {
        vector <int> v; 
        for (int i=v.size(); i>0; i--) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
            v.push_back(curr->val);
        }
        ans = checkValid(currLevel, v);
        currLevel++;
    }
    return ans;
}    

int main () {
    
}