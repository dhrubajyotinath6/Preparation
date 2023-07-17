/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
public:
    Node* dfs(Node* curr, unordered_map<Node*, Node*> &mpp){
        
        vector<Node*> neighbor;
        Node* clone = new Node(curr->val);
        mpp[curr] = clone;
        
        for(auto &neigh : curr->neighbors){
            if(mpp.find(neigh) != mpp.end()){
                neighbor.push_back(mpp[neigh]);
            }
            else{
                neighbor.push_back(dfs(neigh,mpp));
            }
        }
        clone->neighbors = neighbor;
        
        return clone;
    }
    
public:
    Node* cloneGraph(Node* node) {
        
        unordered_map<Node*, Node*> mpp;
        if(node == NULL) return NULL;
        
        if(node->neighbors.size() == 0){ //if only one node present no neighbors
            Node* clone = new Node(node->val);
            return clone;
        }
        
        return dfs(node, mpp);
    }
};