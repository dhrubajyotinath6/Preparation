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
    
    bool union_set(int u, int v) {
        
        u = find(u);
        v = find(v);
        
        //same parent
        if(u == v){
            return false;
        }else if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[v] < rank[u]) {
            parent[v] = u; 
        }else {
            parent[v] = u;
            rank[u]++; 
        }
        
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        //here we need to initialise n+1 , not n
        //bcoz if there are 5 nodes, then there will be 5 edges
        //but nodes are named from 1 - 5 
        UnionFind dsu(n+1);
        for(auto& edge : edges){
            if(!dsu.union_set(edge[0], edge[1])) return edge;
        }
        
        return {};
    }
};