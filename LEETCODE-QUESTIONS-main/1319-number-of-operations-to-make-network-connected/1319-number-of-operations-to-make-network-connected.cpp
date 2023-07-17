/*
There are no repeated connections.

No two computers are connected by more than one cable
*/

//https://github.com/dhrubajyotinath6/Preparation/blob/master/DSA/STRIVER/graphs%20--%20striver/3.2.%20KruskalAlgorithm.Cpp
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
    int makeConnected(int n, vector<vector<int>>& connections) {
         
        //If less cable are there , then it is not possible to connect all components
         if (connections.size() < n - 1) {
            return -1;
        }
        
        UnionFind dsu(n);
        int numberOfConnectedComponents = n;
        
        for(auto& connection : connections){
            if(dsu.find(connection[0]) != dsu.find(connection[1])){
                numberOfConnectedComponents--;
                dsu.union_set(connection[0], connection[1]);
            }
        }
        
        return numberOfConnectedComponents - 1;
    }
};



/*

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[node] = true;
        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {
                dfs(neighbor, adj, visit);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int numberOfConnectedComponents = 0;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfConnectedComponents++;
                dfs(i, adj, visit);
            }
        }

        return numberOfConnectedComponents - 1;
    }
};

*/

/*

class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int numberOfConnectedComponents = 0;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfConnectedComponents++;
                bfs(i, adj, visit);
            }
        }

        return numberOfConnectedComponents - 1;
    }
};

*/