class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) { 
        
        
        unordered_map<int,int> inDegree;
        unordered_map<int,vector<int>> graph;
        
        for(auto seq : sequences){
            for(int i = 0; i < seq.size(); i++){
                inDegree[seq[i]] = 0;
                graph[seq[i]] = vector<int>();
            }
                        
        }
        
        for(auto seq : sequences){
            for(int i = 1; i < seq.size(); i++){
                int par = seq[i-1], child = seq[i];
                graph[par].push_back(child);
                inDegree[child]++;
            }
        }
        
        vector<int> sortedOrder;
        
        if(inDegree.size() != nums.size()) return false;
        
        queue<int> sources;
    
        for (auto entry : inDegree) {
          if (entry.second == 0) {
            sources.push(entry.first);
          }
        }


        while (!sources.empty()) {
            
            if(sources.size() > 1) return false;
            
            //the next source (or number) is different from original sequence
            if (nums[sortedOrder.size()] != sources.front()) return false;
        

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
        
        return sortedOrder.size() == nums.size();
    } 

};