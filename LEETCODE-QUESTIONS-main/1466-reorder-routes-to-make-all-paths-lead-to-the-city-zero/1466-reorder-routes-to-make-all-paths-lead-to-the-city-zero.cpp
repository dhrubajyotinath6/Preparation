/*

we hv to travel from parent to child

if there is already parent -> child , add 1;
if there is already child -> parent , add 0;

case 1: (add 1)

  there is parent -> child  => 1
  artifical : child -> parent 
  
case 2: (add 0)
  there is child -> parent 
  artifical: parent -> child  => 0

*/


class Solution {
    
public:
    
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, int &count) {
        
        for (auto& [child, sign] : adj[node]) {
            if (child != parent) {
                count += sign;
                dfs(child, node, adj, count);
            }
        }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& connection : connections){
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        
        int count = 0;
        
        dfs(0, -1, adj, count);
        
        return count;
    }
};