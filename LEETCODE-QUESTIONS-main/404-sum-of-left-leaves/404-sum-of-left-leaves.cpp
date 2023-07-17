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
    
    int sum = 0;
    
    void func(TreeNode* root, bool isLeft){
        
        if(isLeft && !root->left && !root->right){
            sum += root->val;
        }
        
        if(root->left) func(root->left, true);
        if(root->right) func(root->right, false);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        func(root,false);
        return sum;
    }
};