/*
https://leetcode.com/problems/validate-binary-search-tree/

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

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

/*
https://leetcode.com/problems/validate-binary-search-tree/discuss/32104/C%2B%2B-in-order-traversal-and-please-do-not-rely-on-buggy-INT_MAX-INT_MIN-solutions-any-more

Input
[2147483647]

Output
false

Expected
true
*/

class Solution {
    
    bool f(TreeNode* node, long mini, long maxi){
        
        if(!node) return true;
        
        if(node->val >= maxi || node->val <= mini) return false;
        
        return f(node->left, mini, node->val) && f(node->right, node->val, maxi);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;
        
        if(!root->left && !root->right) return true;
        
        return f(root, LONG_MIN, LONG_MAX);
    }
};

/*
there is one edge case..if there is 1 node nd that node is equal to maximum or minimum value then
*/