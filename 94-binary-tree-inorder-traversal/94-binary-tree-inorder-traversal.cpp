class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>inorder;
        
        helper(root,inorder);
            
        return inorder;
    }
    
    void helper(TreeNode* root, vector<int> &inorder){        
        if(!root) return;
        
        helper(root->left,inorder);
        inorder.push_back(root->val);
        helper(root->right,inorder);
        
    }
    
};