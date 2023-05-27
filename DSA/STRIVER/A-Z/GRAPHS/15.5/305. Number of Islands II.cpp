//https://leetcode.com/problems/number-of-islands-ii/

class UnionFind{
    
private:
    vector<int> parent, rank;
    int count;
    
public:
    UnionFind(int size){
        parent.resize(size, -1);
        rank.resize(size,1);
        count = 0;
    }
    
    void addLand(int x){
        if(parent[x] >= 0) return;
        parent[x] = x;
        count++;
    }
    
    bool isLand(int x){
        if(parent[x] >= 0){
            return true;
        }else{
            return false;
        }
    }
    
    int numberOfIslands(){
        return count;
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
        
        count--;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        int x[] = {-1, 1, 0, 0};
        int y[] = {0, 0, -1, 1};
        
        UnionFind dsu(m*n);
        vector<int> ans;
        
        for(auto& position : positions){
            int landPosition = position[0]*n + position[1];
            dsu.addLand(landPosition);
            
            for(int i = 0; i < 4; i++){
                int neighborX = position[0] + x[i];
                int neighborY = position[1] + y[i];
                
                int neighborPosition = neighborX*n + neighborY;
                
                if(neighborX >= 0 && neighborX < m && neighborY >= 0 && neighborY < n && dsu.isLand(neighborPosition)){
                    dsu.union_set(landPosition, neighborPosition);
                }
            }
            
            ans.push_back(dsu.numberOfIslands());
        }
        
        return ans;
    }
};