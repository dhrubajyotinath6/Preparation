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
    
    int dfs(TreeNode* node, vector<int> &allSums){
        
        if(node == NULL) return 0;
        
        int leftSum = dfs(node->left, allSums);
        int rightSum = dfs(node->right, allSums);
        
        int totalSum = leftSum + rightSum + node->val;
        allSums.push_back(totalSum);
        
        
        return totalSum;
    }
public:
    int maxProduct(TreeNode* root) {
        
        vector<int> allSums;
        
        long totalSum = dfs(root, allSums);
        long best = 0;
        
        for(auto& sum : allSums){
            best = max(best, sum * (totalSum - sum));
        }
        
        return (int)(best % 1000000007);
    }
};