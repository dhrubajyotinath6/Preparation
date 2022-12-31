/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/solution/  -- check 3rd approch  "peeling onion"

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/1151423/C%2B%2B-Optimization-from-Brute-Force-to-DP-or-Easy-Solution-w-Explanation

*/

/*
Time Complexity : O(NM)
Space Complexity : O(NM)
*/

class Solution {
    
    int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp, int m, int n){
        
        //default value of vector is 0
        if(dp[i][j]) return dp[i][j];
        
        dp[i][j] = 1;
        
        for(int k = 0; k < 4; k++){
            int new_i = i + moves[k][0], new_j = j + moves[k][1];
            
            if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || matrix[new_i][new_j] <= matrix[i][j]){
                continue;
            }
            
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, new_i, new_j, dp, m, n));
        }
        
        return dp[i][j];
        
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size() , n = matrix[0].size();
        
        if(m == 0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n));
        
        int ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(matrix, i, j, dp, m , n));
            }
        }
        return ans;
    }

};



I think it is worthy to mention that for most of this kind of questions that we could not add memorization upon a DFS. 
    This question is a special case. 
        Normally when you could move to 4 directions, there would be cycle so you could not memorize the result. 
        However since this question is strictly increasing, thus it is a DAG.
