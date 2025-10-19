/*
1372. Longest ZigZag Path in a Binary Tree
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
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
            void dfs(TreeNode* root, int dir, int len, int& maxLen)
            {
                if(! root) return;
                maxLen = max(maxLen, len);
                if(dir == 0)
                {
                    dfs(root->right, 1, len + 1, maxLen);
                    dfs(root->left, 0, 1, maxLen);
                }
                else
                {
                    dfs(root->left, 0,  len + 1, maxLen);
                    dfs(root->right, 1, 1, maxLen);
                }
            }
            int longestZigZag(TreeNode* root) {
                int maxLen = 0;
                dfs(root->left, 0, 1, maxLen);
                dfs(root->right, 1, 1, maxLen);
                return maxLen;
            }
        };

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(NULL);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->left->left = new TreeNode(NULL);
    root->right->right->left->right = new TreeNode(1);
    root->right->right->left->right->left = new TreeNode(NULL);
    root->right->right->left->right->right = new TreeNode(1);

    cout<< "Longest Zig-Zag path is : "<<sol.longestZigZag(root);

    return 0;
}
