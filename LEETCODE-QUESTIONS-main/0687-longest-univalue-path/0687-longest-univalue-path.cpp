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
public:
    int dfs(TreeNode* node, int &ans){
        
        if(!node) return 0;
        
        int left = dfs(node->left, ans);
        int right = dfs(node->right, ans);
        
        if(node->left != NULL){
            if(node->left->val != node->val) left = 0;
            else left++;
        }
        
        if(node->right != NULL){
            if(node->right->val != node->val) right = 0;
            else right++;
        }       
        
        
        ans = max(ans, left + right);
        return max(left, right);
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};