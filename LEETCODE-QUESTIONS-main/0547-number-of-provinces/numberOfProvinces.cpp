/*
1. DFS
2. Union find
https://leetcode.com/problems/number-of-provinces/
*/

class Solution {
public:
    void join(int u, int v, vector<int> &parent, vector<int> &rank) {
        
    u = findPar(u, parent);
    v = findPar(v, parent);
        
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}

public:
    int findPar(int u, vector<int> &parent) {
        
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
        
}
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
    int n = isConnected.size();
    vector<int> parent(n);
	for(int i = 0;i<n;i++){
        parent[i] = i;
    }
        
    vector<int> rank(n, 0);
	    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1 && i != j){
                join(i, j, parent, rank);
            }
        }
    }
        
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(parent[i] == i) ans++;
    }
        
    return ans;
        
    }
};
