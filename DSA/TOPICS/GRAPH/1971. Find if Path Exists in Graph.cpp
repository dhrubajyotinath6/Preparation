There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path 
from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.




//https://leetcode.com/problems/find-if-path-exists-in-graph/solution/
//TRY THIS : Approach 4: Disjoint Set Union (DSU)

/*
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>> graph;
        
        for(auto &edge : edges){
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int> vis(n,0);
        vis[source] = 1;
        
        queue<int> bfs;
        bfs.push(source);
        
        while(!bfs.empty()){
            int currNode = bfs.front();
            bfs.pop();
            
            if(currNode == destination) return true;
            
            for(auto &nextNode : graph[currNode]){
                if(vis[nextNode] == 0){
                    vis[nextNode] == 1;
                    bfs.push(nextNode);
                }
            }
        }
        return false;
    }
};


tc - O(n+m)
sc - O(n+m)
*/


/*
Approach 4: Disjoint Set Union (DSU)

we have to join all the elements and find the parent of source and destination
if their parents same, then path exists otherwise No
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        

    vector<int> parent(n);
	for(int i = 0;i<n;i++){
        parent[i] = i;
    }
        
    vector<int> rank(n, 0);
	    
    for(auto edge : edges){
        join(edge[0],edge[1], parent, rank);
    }
        
    return findPar(source, parent) == findPar(destination, parent);
        
    }
};

