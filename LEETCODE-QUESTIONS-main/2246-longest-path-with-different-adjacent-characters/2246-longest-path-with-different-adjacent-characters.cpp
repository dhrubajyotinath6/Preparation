class Solution {
    
public:
    int dfs(int currentNode, vector<vector<int>> &adj, string &s, int &longestPath){
        
        int longestChain = 0, secondLongestChain = 0;
        
        for(auto& child : adj[currentNode]){
            
            int longestChainStartingFromChild = dfs(child, adj, s, longestPath);
            
            if(s[currentNode] == s[child]) continue;
            
            if(longestChainStartingFromChild > longestChain){
                secondLongestChain = longestChain;
                longestChain = longestChainStartingFromChild;
            }else if(longestChainStartingFromChild > secondLongestChain){
                secondLongestChain = longestChainStartingFromChild;
            }
        }
        
        longestPath = max(longestPath, longestChain + secondLongestChain + 1);
        return longestChain + 1;
        
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }
        
        int longestPath = 1;
        dfs(0, adj, s, longestPath);
        
        return longestPath;
    }
};