
class Solution {
    
public:
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<bool>& hasApple){
        
        int totalTime = 0, childTime = 0;
        
       
        for(auto child : adj[node]){
            if(child == parent) continue;
            
            
            childTime = dfs(child, node, adj, hasApple);
 

// if childTime is not ZERO, it means we have n apple below , so we do need to visit the node
// if that particular node has APPLE, we need to visit the node

            
            if(hasApple[child] || childTime) totalTime += childTime + 2;
        }
        
        return totalTime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        return dfs(0, -1, adj, hasApple);
    }
};

    
