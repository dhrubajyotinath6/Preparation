/*
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/solution/

1. dfs
2. union find

*/

//dfs
class Solution {

public:
    void dfs(vector<vector<int>> &graph, vector<int> &visit, int src){
        
        visit[src] = 1;
        
        for(auto &child : graph[src]){
            // cout << src << " " << child;
            if(visit[child] == 0){
                dfs(graph, visit, child);
            }
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        if(n == 0) return 0;
        int comp = 0;
        
        vector<int> visit(n, 0);
        vector<vector<int>> graph(n);
        
        for(auto &edge : edges){
            int a = edge[0];
            int b = edge[1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i = 0; i < n; i++){
            
            if(!visit[i]){
                comp++;
                dfs(graph, visit, i);
            }
        }
        return comp;
    }
};