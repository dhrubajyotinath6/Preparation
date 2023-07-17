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