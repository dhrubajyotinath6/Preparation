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