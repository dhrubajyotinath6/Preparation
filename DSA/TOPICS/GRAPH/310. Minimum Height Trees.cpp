/*
https://leetcode.com/problems/minimum-height-trees/
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