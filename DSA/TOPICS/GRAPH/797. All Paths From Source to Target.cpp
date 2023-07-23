Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths 
from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
(i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.


//acyclic graph  -- no cycle -- very very imp

//https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118691/C%2B%2BPython-Backtracking

//https://leetcode.com/problems/all-paths-from-source-to-target/discuss/986429/Python-Iterative-DFS-with-detailed-time-complexity-and-visuals


class Solution {
    
public:
    void dfs(vector<vector<int>> graph, vector<vector<int>> &paths, vector<int> &path, int curr){
        path.push_back(curr);
        
        if(curr == graph.size() - 1) paths.push_back(path);
        else{
            
            for(auto& it : graph[curr])
                dfs(graph, paths, path, it);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        
        dfs(graph, paths, path, 0);
        return paths;
    }
};
