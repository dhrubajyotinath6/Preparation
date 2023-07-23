Given an integer n, return all the structurally unique BST (binary search trees), 
which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 8



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
 
 https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/929000/Recursive-solution-long-explanation/1157959
 
 */
class Solution {
public:
    vector<TreeNode*> rec( int start , int end  ){
        
      if( start > end ){
        return {NULL};
      }
        
      vector<TreeNode*> leftlist, rightlist,result;
        
      for( int i = start ; i <= end ; i++ ){
          
        leftlist = rec( start , i-1 );
        rightlist = rec( i+1,end);
          
        for( auto l : leftlist ){
          for( auto r : rightlist ){
              
            TreeNode* node = new TreeNode(i);
            node->left = l;
            node->right = r;
            result.push_back(node);
              
          }
        }
      }
      
      return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return rec( 1, n );
    }
};