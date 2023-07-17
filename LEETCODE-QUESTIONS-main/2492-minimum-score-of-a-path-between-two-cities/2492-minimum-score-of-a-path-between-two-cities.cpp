/*
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.


Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
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
    int minScore(int n, vector<vector<int>>& roads) {
        
        UnionFind dsu(n+1);
        
        int answer = numeric_limits<int>::max();

        for (auto& road : roads) {
            dsu.union_set(road[0], road[1]);
        }

        for (auto& road : roads) {
            if (dsu.find(1) == dsu.find(road[0])) {
                answer = min(answer, road[2]);
            }
        }

        return answer;
    }
};


/*
class Solution {
public:
    int bfs(int& n, vector<vector<pair<int, int>>>& adj) {
        vector<bool> visit(n + 1);
        queue<int> q;
        int answer = numeric_limits<int>::max();

        q.push(1);
        visit[1] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& edge : adj[node]) {
                answer = min(answer, edge.second);
                if (!visit[edge.first]) {
                    visit[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return answer;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        return bfs(n, adj);
    }
};
*/


/*
class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visit, int& answer) {
        visit[node] = true;
        for (auto& edge : adj[node]) {
            answer = min(answer, edge.second);
            if (!visit[edge.first]) {
                dfs(edge.first, adj, visit, answer);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<bool> visit(n + 1);
        int answer = numeric_limits<int>::max();
        dfs(1, adj, visit, answer);

        return answer;
    }
};


*/