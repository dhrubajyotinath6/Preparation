/*
https://leetcode.com/problems/minimum-height-trees/


A tree is an undirected graph in which any two vertices are connected by exactly one path. 
In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges 
where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi 
in the tree, you can choose any node of the tree as the root. When you select a node x as the root, 
the result tree has height h. Among all possible rooted trees, those with minimum height 
(i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.


Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> ans;
        
        if(n <= 0) return ans;
        
        if(n == 1){
            ans.push_back(0);
            return ans;
        }
        
        unordered_map<int,int> inDegree;
        unordered_map<int,vector<int>> graph;
        
        for(int i = 0; i < n; i++){
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        
        for(int i = 0; i < edges.size(); i++){
            int n1 = edges[i][0], n2 = edges[i][1];
            
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
            
            inDegree[n1]++;
            inDegree[n2]++;
        }
        
        queue<int> leaves;
        
        for(auto entry : inDegree){
            if(entry.second == 1) leaves.push(entry.first);
        }
        
        int totalNodes = n;
        
        while(totalNodes > 2){
            
            int size = leaves.size();
            totalNodes -= size;
            
            for(int i = 0; i < size; i++){
                int top = leaves.front();
                leaves.pop();
                
                vector<int> children = graph[top];
                
                for(auto child : children){
                    inDegree[child]--;
                    if(inDegree[child] == 1) leaves.push(child);
                }                
            }
            
        }
       
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
       return ans; 
    }
};