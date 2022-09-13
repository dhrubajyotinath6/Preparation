//https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    
    int f(TreeNode* node, int maxi, int &count){
        
        if(node == NULL) return 0;
        
        if(node->val >= maxi) count++;
        
        maxi = max(maxi,node->val);
        
        if(node->left) f(node->left, maxi, count);
        if(node->right) f(node->right, maxi, count);
        
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int count = 1;
        
        f(root->left, root->val, count);
        f(root->right,root->val, count);
        
        return count;
    }
};