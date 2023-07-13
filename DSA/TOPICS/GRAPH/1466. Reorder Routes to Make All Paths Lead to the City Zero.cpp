There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. 
Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 

Example 1:


Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).


Example 2:


Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).


Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi



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