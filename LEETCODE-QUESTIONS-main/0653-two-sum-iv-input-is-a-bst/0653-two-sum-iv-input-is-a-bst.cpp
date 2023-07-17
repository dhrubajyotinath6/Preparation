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
 
 https://leetcode.com/problems/two-sum-iv-input-is-a-bst/solution/
 check approch 3 -> inorder transversal, then apply 2 sum
 */
class Solution {

public:
    bool twoSum(TreeNode* node, int k, unordered_set<int> &s){
        if(!node) return false;
        
        if(s.find(k - node->val) != s.end()) return true;
        
        s.insert(node->val);
        
        return twoSum(node->left, k, s) || twoSum(node->right, k, s);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        
        unordered_set<int> s;
        return twoSum(root, k, s);
    }
};