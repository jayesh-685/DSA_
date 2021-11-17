#include "bits/stdc++.h"
using namespace std;

/* Binary Search Tree is a node-based binary tree data structure which has the following properties:
The left subtree of a node contains only nodes with keys lesser than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
The left and right subtree each must also be a binary search tree.
There must be no duplicate nodes. */

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

bool bstSearchR (Node* root, int x) {
    if (root == NULL)
        return false;
    else if (root->key == x)
        return true;
    else if (x < root->key)
        return bstSearchR(root->left, x);
    else 
        return bstSearchR(root->right, x);
}
// O(H) both time complexity and aux space 

bool bstSearchI (Node* root, int x) {
    while (root != NULL) {
        if (root->key == x)
            return true;
        else if (x > root->key)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}
// O(H) O(1)    so it is better than the recursive solution
// time complexity is best when tree is balanced

// my way
/* Node* insertBST_I_I (Node* root, int x) {
    Node* temp = new Node (x);
    if (root == NULL) {
        root = temp;
    }

    while (true) {
        if (root->key == x) {
            break;
        } else if (x > root->key) {
            if (root->right == NULL) {
                root->right = temp;
                break;
            }
            else
                root = root->right;
        } else {
            if (root->left == NULL) {
                root->left = temp;
                break;
            }
            else
                root = root->left;
        }
    }
    return root;
} */

Node* insertBST_I (Node* root, int x) {
    Node* temp = new Node (x);

    Node* curr = root;
    Node* parent = curr;

    while (curr != NULL) {
        parent = curr;
        if (x > curr->key)
            curr = curr->right;
        else if (x < curr->key)
            curr = curr->left;
        else
            return root;    // because element is already present
    }
    if (parent == NULL)
        return temp;
    else if (x > parent->key)
        parent->right = temp;
    else
        parent->left = temp;
    return root;
}
// O(H) O(1)

Node* insertBST_R (Node* root, int x) {
    if (root == NULL)
        return new Node (x);
    else if (x > root->key)
        root->right = insertBST_R(root->right, x);
    else if (x < root->key) 
        root->left = insertBST_R(root->left, x);
    return root;    // this return statement also takes care of the case where x is already present in the tree
}
// O(H) O(H)
// same as search

// BST delete
// 3 scenarios:
// 1.Node to be deleted is a leaf node.
// 2.Node to be deleted has only one child.
// 3.Node to be deleted has two children.
// in 3rd scenario we need to replace the node with inorder successor or inorder predecessor
// inorder successor is the closest higher value and inorder predecessor is the closest lower value.
// if for a node its right sub tree exists then we can find its inorder successor by finding the leftmost leaf of its right child... for any arbitrary node the mechanism is more complex
// similarly if left sub tree exists then we can find its inorder predecessor by finding the rightmost leaf of its left child

Node* getInorderSuccessor (Node* root) {
    while (root != NULL && root->left != NULL) 
        root = root->left;
    return root;
}

Node* BSTdelete (Node* root, int x) {
    if (root == NULL)
        return root;
    else if (x > root->key) {
        root->right = BSTdelete(root->right, x);
    } 
    else if (x < root->key) {
        root->left = BSTdelete(root->left, x);
    } 
    else {
        // if x == root->key
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
            // this also takes care of the case if both left and right are NULL as temp becomes NULL and we return that
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // if both left and right sub tree exists then we need to find inorder successor
            Node* successor = getInorderSuccessor(root->right);
            root->key = successor->key;
            root->right = BSTdelete(root->right, successor->key);
        }
    }
    return root;
}

void levelOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
}

// given a BST, find the floor of x i.e the largest integer no larger than x.
Node* floor (Node* root, int x) {
    // we will maintain a variable res which we will only update when we go right because we want to find floor
    Node* res =  NULL;
    while (root != NULL) {
        if (root->key == x)
            return root;
        else if (x < root->key)
            root = root->left;
        else {
            res = root;
            root = root->right;
        }
    }
    return res;
}
// traversing across the height of the binary tree so time complexity is O(H) and aux space is O(1)

int main () {
    // Node *root = new Node(30);
    // root->left = new Node(12);
    // root->right = new Node(18);
    // root->left->left = new Node(5);
    // root->left->right = new Node(7);
    // root->right->left = new Node(6);
    // root->right->right = new Node(12);

    // // cout << bstSearchI(root, 567);
    // levelOrderTraversal(root);
    // root = insertBST_I(root, 50);
    // levelOrderTraversal(root);

    // Node* root = NULL;
    // root = insertBST_I(root, 50);
    // root = insertBST_I(root, 32);
    // root = insertBST_I(root, 15);
    // root = insertBST_I(root, 65);
    // root = insertBST_I(root, 16);
    // root = insertBST_I(root, 49);
    // root = insertBST_I(root, 2);
    // levelOrderTraversal(root);

    Node* root = NULL;
    root = insertBST_R(root, 50);
    root = insertBST_R(root, 32);
    root = insertBST_R(root, 15);
    root = insertBST_R(root, 65);
    root = insertBST_R(root, 16);
    root = insertBST_R(root, 49);
    root = insertBST_R(root, 2);
    levelOrderTraversal(root);

    root = BSTdelete(root, 50);
    levelOrderTraversal(root);
}