/*
104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
            int maxDepth(TreeNode* root) {
                if(root == NULL) return 0;
                int left = maxDepth(root->left);
                int right = maxDepth(root->right);
                while(left > right)
                {
                    return left + 1;
                }
                return right + 1;
            }
        };

        TreeNode* insertLevelOrder(vector<int>& arr, int i, int n) {
            if (i >= n || arr[i] == -1) return NULL;  // -1 represents NULL nodes
            TreeNode* root = new TreeNode(arr[i]);
            root->left = insertLevelOrder(arr, 2 * i + 1, n);
            root->right = insertLevelOrder(arr, 2 * i + 2, n);
            return root;
        }

        void inorder(TreeNode* root) {
            if (!root) return;
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }

int main()
{
    Solution solution;
    vector<int> data = {3,9,20,-1,-1,15,7};
    TreeNode* root = insertLevelOrder(data, 0, data.size());
    cout<<"Inorder traversal of tree :";
    inorder(root);
    cout<<endl;
    cout<<"Max depth of Tree : "<<solution.maxDepth(root)<<endl;
    return 0;
}


