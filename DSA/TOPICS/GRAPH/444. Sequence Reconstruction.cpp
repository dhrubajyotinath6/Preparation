/*
https://leetcode.com/problems/sequence-reconstruction/

*/

Example 1:

Input: nums = [1,2,3], sequences = [[1,2],[1,3]]
Output: false
Explanation: There are two possible supersequences: [1,2,3] and [1,3,2].
The sequence [1,2] is a subsequence of both: [1,2,3] and [1,3,2].
The sequence [1,3] is a subsequence of both: [1,2,3] and [1,3,2].
Since nums is not the only shortest supersequence, we return false.




Example 2:

Input: nums = [1,2,3], sequences = [[1,2]]
Output: false
Explanation: The shortest possible supersequence is [1,2].
The sequence [1,2] is a subsequence of it: [1,2].
Since nums is not the shortest supersequence, we return false.



Example 3:

Input: nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
Output: true
Explanation: The shortest possible supersequence is [1,2,3].
The sequence [1,2] is a subsequence of it: [1,2,3].
The sequence [1,3] is a subsequence of it: [1,2,3].
The sequence [2,3] is a subsequence of it: [1,2,3].
Since nums is the only shortest supersequence, we return true.


=>
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