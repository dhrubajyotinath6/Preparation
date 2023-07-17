class Solution {
public:
    bool bipartiteDfs(int node, vector<vector<int>>& graph, int color[]) {
        
        for(auto it : graph[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!bipartiteDfs(it, graph, color)) {
                    return false; 
                }
            } else if(color[it] == color[node]) return false; 
        }
        return true; 
    }
    
public:    
    bool checkBipartite(vector<vector<int>>& graph, int n) {
        
        int color[n];
        memset(color, -1, sizeof color); 
        
        for(int i = 0;i<n;i++) {
            
            if(color[i] == -1) {
                color[i] = 1;
                if(!bipartiteDfs(i, graph, color)) {
                    return false;
                }
            }
            
        }
        return true; 
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        return checkBipartite(graph, n);
    }
};