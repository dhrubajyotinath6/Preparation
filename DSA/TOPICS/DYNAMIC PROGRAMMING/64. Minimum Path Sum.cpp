Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [
               [1,3,1],
               [1,5,1],
               [4,2,1]
              ]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200




//2D  DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // vector<vector<int>> vec( n , vector<int> (m, 0)); 
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                
                //last row but not last col
                if(i == grid.size() - 1 && j != grid[0].size() - 1)
                    dp[i][j] = grid[i][j] +  dp[i][j + 1];
                
                //last col but not last row
                else if(j == grid[0].size() - 1 && i != grid.size() - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                
                //normal
                else if(j != grid[0].size() - 1 && i != grid.size() - 1)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                // last row, last col
                else
                    dp[i][j] = grid[i][j]; 
            }
        }
        return dp[0][0];
    }
};



//1D  DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<int> dp(grid[0].size(), 0);
        
         for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                
                if(i == grid.size() - 1 && j != grid[0].size() - 1)
                    dp[j] = grid[i][j] +  dp[j + 1];
                
                else if(j == grid[0].size() - 1 && i != grid.size() - 1)
                    dp[j] = grid[i][j] + dp[j];
                
                else if(j != grid[0].size() - 1 && i != grid.size() - 1)
                    dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
                
                else
                    dp[j] = grid[i][j];
            }
        }
        return dp[0];
    }
};



//Dynamic Programming (Without Extra Space)


public class Solution {
    public int minPathSum(int[][] grid) {
        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = grid[0].length - 1; j >= 0; j--) {

                //last row but not last col
                if(i == grid.length - 1 && j != grid[0].length - 1)
                    grid[i][j] = grid[i][j] +  grid[i][j + 1];

                //last col but not last row
                else if(j == grid[0].length - 1 && i != grid.length - 1)
                    grid[i][j] = grid[i][j] + grid[i + 1][j];

                //normal
                else if(j != grid[0].length - 1 && i != grid.length - 1)
                    grid[i][j] = grid[i][j] + Math.min(grid[i + 1][j],grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
}






