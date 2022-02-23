/*
https://leetcode.com/problems/invert-binary-tree/

example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]


ex: 2
Input: root = [2,1,3]
Output: [2,3,1]


Example 3:
Input: root = []
Output: []
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    void func(TreeNode* root){
         
        if(!root){
            return;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        
        func(root);
        return root;
        
    }
};