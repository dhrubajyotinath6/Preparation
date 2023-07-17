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
 
 https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/98101/Proper-O(1)-space    -- very imp
 
 https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/98191/C%2B%2B-O(n)-time-and-O(1)-space-by-inorder-traversal
 */
class Solution {

public:
    void inorder(TreeNode* node, int &maxFreq, int &currFreq, int &pre, vector<int> &ans){
        
        if(node == NULL) return;
        
        inorder(node->left, maxFreq, currFreq, pre, ans);
        
        if(pre == node->val) currFreq++;
        else{
            currFreq = 1;
        }
        
        
        if(currFreq > maxFreq){
            ans.clear();
            maxFreq = currFreq;
            ans.push_back(node->val);
        }
        else if(currFreq == maxFreq){
            ans.push_back(node->val);
        }
        
        pre = node->val;
        
        inorder(node->right, maxFreq, currFreq, pre, ans);
    }
public:
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        int maxFreq = 0, currFreq = 0, pre = INT_MIN;
        
        inorder(root, maxFreq, currFreq, pre, ans);
        
        return ans;
    }
};
