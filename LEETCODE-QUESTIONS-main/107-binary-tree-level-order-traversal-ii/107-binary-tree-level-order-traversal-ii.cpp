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
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/35108/C%2B%2B-4ms-solution!
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/34970/Is-there-any-better-idea-than-doing-regular-level-order-traversal-and-reverse-the-result

// vector<vector<int>> iterator it;
//             it = result.begin();
//             result.insert (it,row);

class Solution {
     
    //DEPTH FUNCTION
    int depth(TreeNode *root) {
        
    if (!root) return 0;
        
    int lh = depth(root->left);
    int rh = depth(root->right);
        
    return max(lh,rh)+1;
    }
    
    //LEVELORDER FUNCTION
    vector<vector<int>> levelOrder(vector<vector<int>> &ans, TreeNode *root, int level){
        
        if(!root) return ans;
        
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);
            
            for(int i = 0; i < size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                
                int index = i;
                row[index] = node->val;
                
                if(node->left) nodesQueue.push(node->left);
                if(node->right) nodesQueue.push(node->right);
            }
            ans[level]=row;
            level--;
                                   
        }
        return ans;
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int d = depth(root);
        
        vector<vector<int>> ans(d,vector<int> {});
        levelOrder(ans,root,d-1);
        return ans;
        
       
        
    }
};