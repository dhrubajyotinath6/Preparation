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
    
    void post(Node* node, vector<int> &ans){
        
        for(auto child : node->children) post(child, ans);
        
        ans.push_back(node->val);
    }
        
public:
    vector<int> postorder(Node* root) {
        
        vector<int> ans;
        
        if(!root) return ans;
        
        post(root, ans);
        
        return ans;
    }
};