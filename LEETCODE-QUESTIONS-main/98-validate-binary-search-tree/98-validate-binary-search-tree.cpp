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

/*
https://leetcode.com/problems/validate-binary-search-tree/discuss/32104/C%2B%2B-in-order-traversal-and-please-do-not-rely-on-buggy-INT_MAX-INT_MIN-solutions-any-more

Input
[2147483647]

Output
false

Expected
true
*/

class Solution {
    
    bool f(TreeNode* node, long mini, long maxi){
        
        if(!node) return true;
        
        if(node->val >= maxi || node->val <= mini) return false;
        
        return f(node->left, mini, node->val) && f(node->right, node->val, maxi);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;
        
        if(!root->left && !root->right) return true;
        
        return f(root, LONG_MIN, LONG_MAX);
    }
};

/*
there is one edge case..if there is 1 node nd that node is equal to maximum or minimum value then
*/