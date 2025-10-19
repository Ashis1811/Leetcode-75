/*
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
            vector<int> rightSideView(TreeNode* root) {
                vector<int> ans;
                if(! root) return ans;
                queue<TreeNode*> q;
                q.push(root);
                while(! q.empty())
                {
                    int level = q.size();
                    for(int i = 0; i < level; i++)
                    {
                        TreeNode* node = q.front();
                        q.pop();
                        if(i == level - 1)
                        {
                            ans.push_back(node->val);
                        }
                        if(node->left) q.push(node->left);
                        if(node->right) q.push(node->right);
                    }
                }
                return ans;
            }
        };

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(NULL);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(NULL);
    root->right->right = new TreeNode(4);
    vector<int> result = sol.rightSideView(root);
    cout<<"The result is : ";
    for(auto num : result)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
