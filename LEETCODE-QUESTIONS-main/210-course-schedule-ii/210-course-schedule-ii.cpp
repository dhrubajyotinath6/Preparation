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