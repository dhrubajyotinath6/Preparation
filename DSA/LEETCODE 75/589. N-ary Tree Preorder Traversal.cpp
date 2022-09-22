/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/
*/

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
    
    void f(Node* root, vector<int> &ans){
        
        ans.push_back(root->val);
        
        for(auto child : root->children){
            f(child,ans);
        }
    }
    
public:
    vector<int> preorder(Node* root) {
        
        vector<int> ans;
        
        if(!root) return ans;
        
        f(root, ans);
        
        return ans;
    }
};