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
 https://leetcode.com/problems/find-bottom-left-tree-value/discuss/98843/C%2B%2B-recursive-solution-(beats-100)-with-basic-explanation
 https://leetcode.com/problems/find-bottom-left-tree-value/discuss/345876/C%2B%2B-solution-based-on-BFS-with-runtime-4ms
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        
        int val = root->val;
        
        findBottomLeftValue(root, maxDepth, val, 0);
        
        return val;
    }
    
    void findBottomLeftValue(TreeNode* root, int &maxDepth, int &val, int depth){
        if(!root) return;
        
        findBottomLeftValue(root->left, maxDepth, val, depth + 1);
        findBottomLeftValue(root->right, maxDepth, val, depth+1);
        
        if(depth > maxDepth){
             maxDepth = depth;
             val = root->val;
         }
           
        
    }
};