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
    int dfs(TreeNode* node, int currMax, int currMin){
        
        if(node == NULL){
            return currMax - currMin;
        }
        
        currMax = max(currMax, node->val);
        currMin = min(currMin, node->val);
        
        int left = dfs(node->left, currMax, currMin);
        int right = dfs(node->right, currMax, currMin);
        
        return max(left, right);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        
        if(root == NULL) return 0;
        return dfs(root, root->val, root->val);        
    }

};