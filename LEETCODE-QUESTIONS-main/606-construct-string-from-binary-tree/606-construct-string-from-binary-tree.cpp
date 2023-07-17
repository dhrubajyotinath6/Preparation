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
 https://leetcode.com/problems/construct-string-from-binary-tree/discuss/104098/JavaC%2B%2B-1-liner
 https://leetcode.com/problems/construct-string-from-binary-tree/discuss/104089/Easy-C%2B%2B-Solution
 
 
Time Complexity: O(N) where N is the number of the nodes in the tree
Space Complexity: O(H) where H is the height of the tree. 
In worse case, H can be N when it is a left skewed binary tree / right skewed binary tree
 */
/*
class Solution {
public:
    string tree2str(TreeNode* root) {
        
        if(!root) return "";
        
        string s = to_string(root->val);
        
        if(root->left) s += "(" + tree2str(root->left) + ")";
        else if( root->right) s += "()";
        
        if (root->right) s += "(" + tree2str(root->right) + ")";
        
        return s;
    }
};
*/

class Solution {
public:
    string tree2str(TreeNode* root) {
        
        if(!root) return "";
        
        string s = to_string(root->val);
        
        if(root->left) s += "(" + tree2str(root->left) + ")";
        
        if(root->right && root->left == NULL) {
            s += "()(" + tree2str(root->right) + ")";
        }
        
        if (root->right && root->left != NULL) s += "(" + tree2str(root->right) + ")";
        
        return s;
    }
};