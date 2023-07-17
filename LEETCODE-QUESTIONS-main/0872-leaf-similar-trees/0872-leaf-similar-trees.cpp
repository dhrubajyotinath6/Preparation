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
    void inorder(TreeNode* node, vector<int> &leaves){
        
        if(!node) return;
        
        inorder(node->left, leaves);
        if(node->left == NULL && node->right == NULL){
            leaves.push_back(node->val);
        }
        inorder(node->right, leaves);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaves1;
        vector<int> leaves2;
        
        inorder(root1, leaves1);
        inorder(root2, leaves2);
        
        return leaves1 == leaves2;
    }
};