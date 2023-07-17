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
 
 https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/discuss/1612105/3-Steps
 */

/*
Build directions for both start and destination from the root.
Say we get "LLRRL" and "LRR".

Remove common prefix path.
We remove "L", and now start direction is "LRRL", and destination - "RR"

Replace all steps in the start direction to "U" and add destination direction.
The result is "UUUU" + "RR".
*/
class Solution {
    
    bool find(TreeNode* node, int val, string &path){
        
        if(node->val == val) return true;
        
        if(node->left && find(node->left, val, path))
            path.push_back('L');
        
        else if(node->right && find(node->right, val, path))
            path.push_back('R');
        
        return !path.empty();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string start, end;
        
        find(root, startValue, start);
        find(root, destValue, end);
        
        while(!start.empty() && !end.empty() && start.back() == end.back()){
            start.pop_back();
            end.pop_back();
        }
        
        return string(start.size(), 'U') + string(rbegin(end), rend(end));
    }
};