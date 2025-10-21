/*
450. Delete Node in a BST
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
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
            TreeNode* findMin(TreeNode* root)
            {
                while(root->left) root = root->left;
                return root;
            }
            TreeNode* deleteNode(TreeNode* root, int key) {
                if(! root) return NULL;
                if(key < root->val)
                {
                    root->left = deleteNode(root->left, key);
                }
                else if(key > root->val)
                {
                    root->right = deleteNode(root->right, key);
                }
                else
                {
                    if(! root->left) return root->right;
                    if(! root->right) return root->left;
                    TreeNode* curr = findMin(root->right);
                    root->val = curr->val;
                    root->right = deleteNode(root->right, curr->val);
                }
                return root;
            }
        };

int main()
{   
    Solution sol;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(NULL);
    root->right->right = new TreeNode(7);
    int key;
    cout<<"Give key ";
    cin>>key;
    cout<<"The result is : "<<sol.deleteNode(root, key);
    return 0;
}
