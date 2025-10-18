/*
872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
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
            void helper(TreeNode* root, vector<int>& leaf)
            {
                if(! root) return;
                if(! root->left && ! root->right)
                {
                    leaf.push_back(root->val);
                }
                helper(root->left, leaf);
                helper(root->right, leaf);
            }
            bool leafSimilar(TreeNode* root1, TreeNode* root2) {
                vector<int> leaf1, leaf2;
                helper(root1, leaf1);
                helper(root2, leaf2);
                return leaf1 == leaf2;
        
            }
        };

        TreeNode* createRoot1() {
            TreeNode* root = new TreeNode(3);
            root->left = new TreeNode(5);
            root->right = new TreeNode(1);
            root->left->left = new TreeNode(6);
            root->left->right = new TreeNode(2);
            root->right->left = new TreeNode(9);
            root->right->right = new TreeNode(8);
            root->left->right->left = new TreeNode(7);
            root->left->right->right = new TreeNode(4);
            return root;
        }
        TreeNode* createRoot2() {
            TreeNode* root = new TreeNode(3);
            root->left = new TreeNode(5);
            root->right = new TreeNode(1);
            root->left->left = new TreeNode(6);
            root->left->right = new TreeNode(7);
            root->right->left = new TreeNode(4);
            root->right->right = new TreeNode(2);
            root->right->right->left = new TreeNode(9);
            root->right->right->right = new TreeNode(8);
            return root;
        }
int main()
{
    Solution sol;
    TreeNode* root1 = createRoot1();
    TreeNode* root2 = createRoot2();
    if(sol.leafSimilar(root1, root2))
    {
        cout<<"True ";
    }
    else{
        cout<<"False ";
    }
    return 0;
}
