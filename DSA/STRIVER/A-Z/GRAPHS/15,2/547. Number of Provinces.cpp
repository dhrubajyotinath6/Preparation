//https://leetcode.com/problems/number-of-provinces/


There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, 
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city 
and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
/*
1. DFS
2. Union find

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