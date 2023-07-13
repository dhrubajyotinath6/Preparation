We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person 
labeled ai does not like the person labeled bi, return true if it is possible to split everyone 
into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= ai < bi <= n
All the pairs of dislikes are unique.


//https://leetcode.com/problems/possible-bipartition/solution/  -- check approach 3 (union find)


class Solution {
    
public:
    
    bool bipartiteBfs(int src, vector<vector<int>> &adj, vector<int>& color) {
        
    queue<int>q;
    q.push(src);
        
    color[src] = 1; 
        
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
    
public:  
    bool checkBipartite(vector<vector<int>> &adj, int n) {
        
    vector<int> color(n + 1, -1);
        
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
    vector<vector<int>> adj(n + 1);;
        
	for(auto &dislike : dislikes) {
	    adj[dislike[0]].push_back(dislike[1]); 
	    adj[dislike[1]].push_back(dislike[0]); 
	}
	
	if(checkBipartite(adj, n)) {
	    return true;
    }
        
    return false;
 
    }
};