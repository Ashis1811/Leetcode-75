/*
1448. Count Good Nodes in Binary Tree
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
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
            int count = 0;
            void dfs (TreeNode* root, int curr)
            {
                if(! root) return;
                if(root->val >= curr)
                {
                    count++;
                    curr = root->val;
                }
                dfs(root->left, curr);
                dfs(root->right, curr);
            }
            int goodNodes(TreeNode* root) {
                if(root == NULL) return 0;
                count = 0;
                dfs(root, root->val);
                return count;
            }
        };

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    cout<<"Number of good nodes are : "<<sol.goodNodes(root);
    return 0;
}
