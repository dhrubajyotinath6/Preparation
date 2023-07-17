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
 https://leetcode.com/problems/print-binary-tree/discuss/106270/C%2B%2B-8-lines-O(n)
 */
class Solution {
    
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
       int lh = maxDepth(root->left);
       int rh = maxDepth(root->right);
        
        return max(lh,rh) + 1;
    }
    
    void printTree(TreeNode* root, int start, int end, int d, vector<vector<string>> &res){
        
        res[d][(start + end)/2] = to_string(root->val);
        
        if(root->left) printTree(root->left, start, (start + end)/2, d+1, res);
        if(root->right) printTree(root->right, (start + end)/2 + 1, end, d+1, res);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
         
            int d = maxDepth(root);
        
            vector<vector<string>> res(d, vector<string> ((1<<d) - 1, ""));
            
            printTree(root, 0, res[0].size()-1, 0, res);
        
            return res;
    }
};