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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root == NULL)  return ans;
        
        map<int,map<int, multiset<int>>> nodes;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            
            TreeNode* node = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            nodes[x][y].insert(node->val);
            
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
            
            
        }
        
        
        for(auto q : nodes){
            vector<int> temp;
            for(auto p : q.second){
                temp.insert(temp.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;        
        
    }
};
