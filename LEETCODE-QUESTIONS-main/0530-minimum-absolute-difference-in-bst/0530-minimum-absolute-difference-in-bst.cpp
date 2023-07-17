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
    void inorder(TreeNode* node, int &mini, int &pre){
        
        if(node == NULL) return;
        
        inorder(node->left, mini, pre);
        
        if(pre != -1){
            mini = min(mini, node->val - pre);
        }
        pre = node->val;
        
        inorder(node->right, mini, pre);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        
        //0 <= Node.val <= 105
        int mini = INT_MAX,  pre = -1;
        inorder(root, mini, pre);
        return mini;
    }
};