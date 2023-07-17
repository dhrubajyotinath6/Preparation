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
    
    TreeNode* func(TreeNode* root, int v, int d){
        
         if (d == 0 || d == 1) {
            TreeNode* newroot = new TreeNode(v);
            (d ? newroot->left : newroot->right) = root;
            return newroot;
        }
        if (root && d >= 2) {
            root->left  = func(root->left,  v, d > 2 ? d - 1 : 1);
            root->right = func(root->right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* newroot = func(root, val, depth);
        return newroot;
    }
};