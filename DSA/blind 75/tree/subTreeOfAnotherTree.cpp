/*
https://leetcode.com/problems/subtree-of-another-tree/
https://leetcode.com/problems/subtree-of-another-tree/discuss/102734/19ms-C%2B%2B-solution-beats-99.9
*/


/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
 https://leetcode.com/problems/subtree-of-another-tree/discuss/102734/19ms-C%2B%2B-solution-beats-99.9
 */

-> Two trees are identical when they are recursively identical. 
-> Brute force solution would be recursively compare each node in s with t to check for identical. 
-> Better solution is to only compare nodes in s with the same max depth as t. 
First get max depth of t, then recursively check each node in s, if depth equals, push to a vector.
Then compare each node in the vector with t.

class Solution {
    
    vector<TreeNode*> nodes;
    
    int getDepth(TreeNode* root, int d) {
        
        if(!root) return 0;
        
        int lh = getDepth(root->left, d);
        int rh = getDepth(root->right, d);
        
        int depth = max(lh,rh) + 1;
        
        if (depth == d)
            nodes.push_back(root);
        
      return depth;
    }
    
    bool identical(TreeNode* a, TreeNode* b){
        
        if(!a && !b) return true;
        
        if(!a || !b || a->val != b->val) return false;
        
        return identical(a->left, b->left) && identical(a->right, b->right);
    }
    
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        
        getDepth(root, getDepth(subRoot, -1));
        
        // for(TreeNode* n : nodes){
        //     cout << n -> val << " ";
        // }
        
        for(TreeNode* n : nodes){
            if(identical(n, subRoot))
                return true;
        }
        return false;
        
        
    }
};