Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [
                 [9,9,4],
                 [6,6,8],
                 [2,1,1]
                ]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [
                  [3,4,5],
                  [3,2,6],
                  [2,2,1]
                ]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1


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


