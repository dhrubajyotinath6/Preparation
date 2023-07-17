class UnionFind{
    
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int size) {
        
        parent.resize(size);
        rank.resize(size, 0);
        
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if(u == parent[u]) return u; 
        return parent[u] = find(parent[u]); 
    }
    
    void union_set(int u, int v) {
        
        u = find(u);
        v = find(v);
        
        //same parent
        if(u == v){
            return;
        }else if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[v] < rank[u]) {
            parent[v] = u; 
        }else {
            parent[v] = u;
            rank[u]++; 
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
       int n = vals.size();
        vector<vector<int>> adj(n);
        
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        map<int, vector<int>> valuesToNodes;
        for(int node = 0; node < n; node++){
            valuesToNodes[vals[node]].push_back(node);
        }
        
        UnionFind dsu(n);
        int goodPaths = 0;
        
        for(auto& [value, nodes] : valuesToNodes){
            
            for(int node : nodes){
                for(int neighbor : adj[node]){
                    if(vals[node] >= vals[neighbor]){
                        dsu.union_set(node, neighbor);
                    }
                }
            }
            
            unordered_map<int,int> group;
            
            for(auto& u : nodes){
                group[dsu.find(u)]++;
            }
            
            for(auto& [_, size] : group){
                goodPaths += (size*(size+1)/2);
            }
        }
        
        return goodPaths;
    }
};