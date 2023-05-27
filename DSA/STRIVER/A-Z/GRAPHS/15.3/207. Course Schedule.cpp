//https://leetcode.com/problems/course-schedule/

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