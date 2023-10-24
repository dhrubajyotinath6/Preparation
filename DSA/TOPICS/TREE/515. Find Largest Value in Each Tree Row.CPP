Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1


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
 https://leetcode.com/problems/find-largest-value-in-each-tree-row/discuss/880711/cpp-easy-solution-using-queue(also-attached-other-7-similar-code-problems)
 
 https://leetcode.com/problems/find-largest-value-in-each-tree-row/discuss/99035/C%2B%2B-a-different-approach-(12ms-beats-100)
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> result;
        
        if(!root) return result;
        
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            int maxi = INT_MIN;
            
            for(int i = 0; i < size; i++){
                TreeNode* node = nodesQueue.front();
                
                if(node->val > maxi) maxi = node->val;
                nodesQueue.pop();              
                
                if(node->left) nodesQueue.push(node->left);
                if(node->right) nodesQueue.push(node->right);
            }
            
            result.push_back(maxi);
        }
        return result;
    }
};