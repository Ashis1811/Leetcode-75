/*
437. Path Sum III
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
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
            int dfs(TreeNode* root, long long int currsum, int targetSum)
            {
                if(root == NULL) return 0;
                currsum += root->val;
                int ans = 0;
                if(currsum == targetSum) ans++;
                ans += dfs(root->left, currsum, targetSum);
                ans += dfs(root->right, currsum, targetSum);
                return ans;
            }
            int pathSum(TreeNode* root, int targetSum) {
                if(root == NULL) return 0;
                return dfs(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
            }
        };

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(NULL);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    int targetsum;
    cout<<"Enter target sum : ";
    cin >> targetsum;
    cout<<"The right path is : "<<sol.pathSum(root, targetsum);
    return 0;
}
