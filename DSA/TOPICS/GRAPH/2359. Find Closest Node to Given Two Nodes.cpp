You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has 
at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there 
is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the 
maximum between the distance from node1 to that node, and from node2 to that node is minimized. 

If there are multiple answers, return the node with the smallest index, and 
if no possible answer exists, return -1.

Note that edges may contain cycles.

 

Example 1:


Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a 
smaller maximum distance than 1, so we return node 2.


Example 2:


Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a 
smaller maximum distance than 2, so we return node 2.


//https://leetcode.com/problems/find-closest-node-to-given-two-nodes/discuss/2357694/Two-DFS

class Solution {
    
public:
    
    void dfs(int i, int dist, vector<int>& edges, vector<int>& distFromNode){
        
        while(i != -1 &&  distFromNode[i] == -1){
            
            distFromNode[i] = dist++;
            i = edges[i];
        }        
    }
                              
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int res = - 1;
        int minDist = 1e9;
        
        vector<int> distFromNode1(edges.size(), -1);
        vector<int> distFromNode2(edges.size(), -1);
        
        dfs(node1, 0, edges, distFromNode1);
        dfs(node2, 0, edges, distFromNode2);
        
        for(int i = 0; i < edges.size(); i++){
            
            if(distFromNode1[i] >= 0 && distFromNode2[i] >= 0 && max(distFromNode1[i],distFromNode2[i]) < minDist){
                minDist = max(distFromNode1[i],distFromNode2[i]);
                res = i;
            }
        }
        
        return res;
    }
};

