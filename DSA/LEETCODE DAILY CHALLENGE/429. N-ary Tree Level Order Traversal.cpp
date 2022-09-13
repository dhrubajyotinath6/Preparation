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

************************************************************8

//589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

//https://leetcode.com/problems/n-ary-tree-preorder-traversal/discuss/1167754/Easy-Recursive-and-Iterative-Solutions-w-Comments-and-Explanation

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
    
    void pre(Node* node, vector<int> &ans){
        
        ans.push_back(node->val);
        
        for(auto child : node->children) pre(child, ans);
    }
        
public:
    vector<int> preorder(Node* root) {
        
        vector<int> ans;
        
        if(!root) return ans;
        
        pre(root, ans);
        
        return ans;
    }
};


***************************************

//https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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