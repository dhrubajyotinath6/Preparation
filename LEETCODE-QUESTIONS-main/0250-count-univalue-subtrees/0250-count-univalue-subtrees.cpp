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
    int dfs(TreeNode* node, int &count){
        
        if(node->left == NULL && node->right == NULL){
            count++;
            return true;
        }
        
        bool isUni = true;
        
        if(node->left != NULL){
            isUni = dfs(node->left, count) && node->left->val == node->val; 
        }
        if(node->right != NULL){
            isUni = dfs(node->right, count) && node->right->val == node->val & isUni; 
        }
        
        if(isUni == false) return false;
        count++;
        return true;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        
        if(!root) return 0;
        int count = 0;
        dfs(root, count);
        
        return count;
    }
};