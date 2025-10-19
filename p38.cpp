/*
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

     class Solution {
        public:
            TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                if(! root || root == p || root == q)
                {
                    return root;
                }
                TreeNode* left = lowestCommonAncestor(root->left, p, q);
                TreeNode* right = lowestCommonAncestor(root->right, p, q);
                while(left && right)
                {
                    return root;
                }
                return left ? left : right;
            }
        };

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    cout<<"The LCA of nodes "<<sol.lowestCommonAncestor(root, p, q);
    
    return 0;
}
