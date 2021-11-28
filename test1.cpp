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


    vector <TreeNode*> v;
    void inOrderTraversal (TreeNode* root) {
        if (root == NULL)
            return;
        inOrderTraversal(root->left);
        v.push_back(root);
        inOrderTraversal(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* third = NULL;
        inOrderTraversal(root);
        for (int i=1; i<v.size(); i++) {
            cout << "Hello" << endl;
            if (v[i]->val < v[i-1]->val) {
                if (first == NULL) {
                    first = v[i-1];
                    second = v[i];
                    cout << "Found first and second" << endl;
                }
                else
                    third = v[i];
            }
        }
        if (third == NULL) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
        else {
            int temp = first->val;
            first->val = third->val;
            third->val = temp;
        }
    }
int main () {

    TreeNode* root = new TreeNode (3);
    root->left = new TreeNode (1);
    root->right = new TreeNode (4);
    root->right->left = new TreeNode (2);
    levelOrderTraversal(root);
    recoverTree(root);
    levelOrderTraversal(root);
    return 0;
}