Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
 


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
    void dfs(TreeNode* node, unordered_map<int,int> &mpp){
        if(!node) return;
        
        mpp[node->val]++;
        
        dfs(node->left, mpp);
        dfs(node->right, mpp);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        if(!root) return ans;
        
        unordered_map<int,int> mpp;
              
        dfs(root,mpp);
        
        int maxFreq = 0;
        for(auto &[key, value] : mpp){
            maxFreq = max(maxFreq, value);
        }
        
        for(auto &[key, value] : mpp){
            if(maxFreq == value) ans.push_back(key);
        }
        
        
        return ans;
        
    }
};