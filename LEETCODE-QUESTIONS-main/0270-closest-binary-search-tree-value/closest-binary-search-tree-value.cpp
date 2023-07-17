Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target. 
  If there are multiple answers, print the smallest.
  
  
  
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
https://leetcode.com/problems/closest-binary-search-tree-value/solution/

Approach 1: Recursive Inorder + Linear search, O(N) time

Approach 2: Iterative Inorder, O(k) time
*/

//Approach 3: Binary Search, O(H) time
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        
        int val, closest = root->val;
        
        while(root != NULL){
            val = root->val;
            closest = abs(val-target) < abs(closest-target) ? val:closest;
            
            root = target < root->val ? root->left:root->right;
        }
        return closest;
    }
};
