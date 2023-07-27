https://leetcode.com/problems/course-schedule-ii/
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course 
bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, 
return any of them. If it is impossible to finish all courses, return an empty array.

 */

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].


Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].


Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]


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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> ans;
        
        if(numCourses <= 0) return ans;
        
        unordered_map<int,int> inDegree;
        unordered_map<int,vector<int>> graph;
        
        for(int i = 0; i < numCourses; i++){
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        /*
        [[1,0],[2,0],[3,1],[3,2]]
        
        0 -> should be finished first
        1 -> should be finished after 0
        
        */
        for(int i = 0; i < prerequisites.size(); i++){
            int par = prerequisites[i][1], child = prerequisites[i][0];
            graph[par].push_back(child);
            inDegree[child]++;
        }
        
        topo(graph, inDegree, ans);
        
        if(ans.size() != numCourses) return vector<int>();
        
        return ans;        
        
    }
};