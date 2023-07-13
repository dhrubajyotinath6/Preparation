You are given an integer n, the number of nodes in a directed graph where the nodes are labeled 
from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

 

Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
Example 2:

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]
 

Constraints:

1 <= n <= 100
0 <= redEdges.length, blueEdges.length <= 400
redEdges[i].length == blueEdges[j].length == 2
0 <= ai, bi, uj, vj < n




class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges){

        vector<vector<pair<int, int>>> adj(n);

        //0 -> red
        for (auto& redEdge : redEdges) {
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }

        //1->blue
        for (auto& blueEdge : blueEdges) {
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1));
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        // Start with node 0, with number of steps as 0 and undefined color -1.
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps;
                }
            }
        }
        return answer;
    }
};