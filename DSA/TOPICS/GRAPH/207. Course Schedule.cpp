/*
https://leetcode.com/problems/course-schedule/

*/
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates 
that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. 
So it is impossible.


=> 

class Solution {
    
    void topo(unordered_map<int,vector<int>> &graph, unordered_map<int,int> &inDegree, vector<int> &sortedOrder){
        
        queue<int> sources;
    
        for (auto entry : inDegree) {
          if (entry.second == 0) {
            sources.push(entry.first);
          }
        }


        while (!sources.empty()) {

          int vertex = sources.front();
          sources.pop();

          sortedOrder.push_back(vertex);

          vector<int> children = graph[vertex];  // get the node's children to decrement their in-degrees

          for (auto child : children) {
            inDegree[child]--;
            if (inDegree[child] == 0) {
              sources.push(child);
            }
          }
            
        }
    }  
    

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(numCourses <= 0) return false;
        
        unordered_map<int,int> inDegree;
        unordered_map<int,vector<int>> graph;
        
        for(int i = 0; i < numCourses; i++){
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        
        for(int i = 0; i < prerequisites.size(); i++){
            
            int parent = prerequisites[i][0], child = prerequisites[i][1];
            graph[child].push_back(parent);
            inDegree[parent]++;
        }
        
        vector<int> SortedOrder;
        
        topo(graph, inDegree, SortedOrder);
        
        
        return SortedOrder.size() == numCourses;
    }
    
};