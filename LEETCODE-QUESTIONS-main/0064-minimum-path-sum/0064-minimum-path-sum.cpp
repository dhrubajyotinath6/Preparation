/*
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
*/


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

/*
public class Solution {
    public int minPathSum(int[][] grid) {
        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = grid[0].length - 1; j >= 0; j--) {
                if(i == grid.length - 1 && j != grid[0].length - 1)
                    grid[i][j] = grid[i][j] +  grid[i][j + 1];
                else if(j == grid[0].length - 1 && i != grid.length - 1)
                    grid[i][j] = grid[i][j] + grid[i + 1][j];
                else if(j != grid[0].length - 1 && i != grid.length - 1)
                    grid[i][j] = grid[i][j] + Math.min(grid[i + 1][j],grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
}


*/



