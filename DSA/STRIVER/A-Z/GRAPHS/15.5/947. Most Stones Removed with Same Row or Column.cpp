//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/


//Approach 1: Depth-First Search (DFS)
/*
class Solution {
public:
    // Return true if stone a and b shares row or column
    int shareSameRowOrColumn(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] || a[1] == b[1];
    }
    
    void dfs(vector<vector<int>>& stones, vector<int> adj[], vector<int>& visited, int src) {
        // Mark the stone as visited
        visited[src] = 1;
        
        // Iterate over the adjacent, and iterate over it if not visited yet
        for (int adjacent : adj[src]) {
            if (visited[adjacent] == 0) {
                dfs(stones, adj, visited, adjacent);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        // Adjacency list to store edges
        vector<int> adj[stones.size()];
        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (shareSameRowOrColumn(stones[i], stones[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // Array to mark visited stones
        vector<int> visited(stones.size(), 0);
        // Counter for connected components
        int componentCount = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (visited[i] == 0) {
                // If the stone is not visited yet,
                // Start the DFS and increment the counter
                componentCount++;
                dfs(stones, adj, visited, i);
            }
        }
        
        // Return the maximum stone that can be removed
        return stones.size() - componentCount;
    }
};

*/

//Approach 2: Disjoint Set Union (DSU)

class Solution {
public:
    // Return true if stone a and b shares row or column
    int shareSameRowOrColumn(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] || a[1] == b[1];
    }
    
    // Returns the representative of vertex x
    int find(vector<int>& rep, int x) {
        if (x == rep[x]) {
            return x;
        }
        // Uses Path compression
        return rep[x] = find(rep, rep[x]);
    }
    
    // Combine the stone x and y, and returns 1 if they were not connected
    int performUnion(vector<int>& rep, vector<int>& size, int x, int y) {
        x = find(rep, x);
        y = find(rep, y);
        
        if (x == y) {
            return 0;
        }
        
        if (size[x] > size[y]) {
            rep[y] = x;
            size[x] += size[y];
        } else {
            rep[x] = y;
            size[y] += size[x];
        }
        
        return 1;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<int> rep(stones.size());
        vector<int> size(stones.size());
        // Initialize rep to itself and size as 1
        for (int i = 0; i < stones.size(); i++) {
            rep[i] = i;
            size[i] = 1;
        }
        
        int componentCount = stones.size();
        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (shareSameRowOrColumn(stones[i], stones[j])) {
                    // Decrement the componenets if union invloved merging
                    componentCount -= performUnion(rep, size, i, j);
                }
            }
        }
        
        // Return the maximum stone that can be removed
        return stones.size() - componentCount;
    }
};



/*
4 approach

dfs
union
optimized dfs  
optimized union

https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/solution/

*/


    
    
    























