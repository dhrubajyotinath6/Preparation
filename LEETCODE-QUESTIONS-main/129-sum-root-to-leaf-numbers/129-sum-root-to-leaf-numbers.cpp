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
 https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/1556417/C%2B%2BPython-Recursive-and-Iterative-DFS-%2B-BFS-%2B-Morris-Traversal-O(1)-or-Beats-100
 */

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int cur){
        
        if(!root) return 0;
        
        cur = cur*10 + root->val;
        
        if(!root->left && !root->right) return cur;
        
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
};