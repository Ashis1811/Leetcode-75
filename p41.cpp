/*
700. Search in a Binary Search Tree
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
*/

#include<bits/stdc++.h>
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
            TreeNode* searchBST(TreeNode* root, int val) {
                if(! root) return NULL;
                if(root->val == val) return root;
                else if(root->val < val) return searchBST(root->right, val);
                else return searchBST(root->left, val);
            }
        };

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val;
    cout<<"Give value ";
    cin>>val;
    cout<<"The result is : "<<sol.searchBST(root, val);
    return 0;
}
