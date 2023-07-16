Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's 
and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size(),  m = matrix[0].size();        
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        int maxSide = 0;
        
        for(int j = 0; j < m; j++){ 
            dp[0][j] = matrix[0][j] - '0';
            maxSide = max(maxSide, dp[0][j]);
        }
        for(int i = 0; i < n; i++){ 
            dp[i][0] = matrix[i][0] - '0'; 
            maxSide = max(maxSide, dp[i][0]);
        }
                                                         
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]) );
                    maxSide = max(maxSide, dp[i][j]);
                }
                
                
                // cout << maxSide << endl;
            }
        }
        
        return maxSide*maxSide;
        
    }
};







