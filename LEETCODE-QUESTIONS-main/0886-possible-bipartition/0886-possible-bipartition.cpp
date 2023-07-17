//https://leetcode.com/problems/possible-bipartition/solution/  -- check approach 3 (union find)
class Solution {
    
public:
    
    bool bipartiteBfs(int src, vector<vector<int>> &adj, vector<int>& color) {
        
    queue<int>q;
    q.push(src);
        
    color[src] = 1; 
        
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
    
public:  
    bool checkBipartite(vector<vector<int>> &adj, int n) {
        
    vector<int> color(n + 1, -1);
        
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
    vector<vector<int>> adj(n + 1);;
        
	for(auto &dislike : dislikes) {
	    adj[dislike[0]].push_back(dislike[1]); 
	    adj[dislike[1]].push_back(dislike[0]); 
	}
	
	if(checkBipartite(adj, n)) {
	    return true;
    }
        
    return false;
 
    }
};