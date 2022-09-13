//https://leetcode.com/problems/n-ary-tree-level-order-traversal/solution/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int sz= q.size();
            
            vector<int> temp;
            
            for(int i = 0; i < sz; i++){
                auto top = q.front();
                q.pop();
                
                temp.push_back(top->val);
                
                for(auto child : top->children) q.push(child);
                
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};