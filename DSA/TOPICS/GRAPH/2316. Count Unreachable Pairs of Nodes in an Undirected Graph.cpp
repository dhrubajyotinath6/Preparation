You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. 
You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an 
undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 

Example 1:


Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.



Example 2:


Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
 

Constraints:

1 <= n <= 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges.


//Approach 3: Union-find

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
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        UnionFind dsu(n);
        
        for(auto& edge : edges){
            dsu.union_set(edge[0], edge[1]);
        }
        
        unordered_map<int, int> componentSize;
        for(int i = 0; i < n; i++){
            componentSize[dsu.find(i)]++;
        }
        
        
        long long numberOfPaths = 0;
        long long remainingNodes = n;
        
        for(auto& component : componentSize){
            int size = component.second;
            numberOfPaths += size * (remainingNodes - size);
            remainingNodes -= size;  
        }
        
        return numberOfPaths;
    }
};



//Approach 2: Breadth First Search
/*
class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        int count = 1;
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    count++;
                    q.push(neighbor);
                }
            }
        }
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                sizeOfComponent = bfs(i, adj, visit);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
};

*/


//Approach 1: Depth First Search
/*
class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        int count = 1;
        visit[node] = true;
        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {
                count += dfs(neighbor, adj, visit);
            }
        }
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                sizeOfComponent = dfs(i, adj, visit);
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
};

*/