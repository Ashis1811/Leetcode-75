/*
1161. Maximum Level Sum of a Binary Tree
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
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
            int maxLevelSum(TreeNode* root) {
                if(! root) return 0;
                queue<TreeNode*> q;
                q.push(root);
                int level = 0, maxlevel = 1, maxSum = root->val;
                while(! q.empty())
                {
                    level++;
                    int levelsum = 0;
                    int size = q.size();
                    for(int i = 0; i < size; i++)
                    {
                        TreeNode* node = q.front();
                        q.pop();
                        levelsum += node->val;
                        if(node->left) q.push(node->left);
                        if(node->right) q.push(node->right);
                    }
                    if(levelsum > maxSum)
                    {
                        maxSum = levelsum;
                        maxlevel = level;
                    }
                }
                return maxlevel;
            }
        };

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    cout<<"The level is : "<<sol.maxLevelSum(root);
    return 0;
}
