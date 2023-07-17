/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int minFallingSum = INT_MAX;
        
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, findMin(matrix, 0, startCol));
        }
        return minFallingSum;
    }

    int findMin(vector<vector<int>>& matrix, int row, int col) {
        
        // check if we are out of the left or right boundary of the matrix
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMin(matrix, row + 1, col);
        int middle = findMin(matrix, row + 1, col + 1);
        int right = findMin(matrix, row + 1, col - 1);

        return min(left, min(middle, right)) + matrix[row][col];
    }
};

*/

/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int minFallingSum = INT_MAX;
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));
        
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, findMin(matrix, 0, startCol,dp));
        }
        return minFallingSum;
    }

    int findMin(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &dp) {
        
        // check if we are out of the left or right boundary of the matrix
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        
        if(dp[row][col] != -1) return dp[row][col];

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMin(matrix, row + 1, col, dp);
        int middle = findMin(matrix, row + 1, col + 1, dp);
        int right = findMin(matrix, row + 1, col - 1, dp);

        return dp[row][col] = min(left, min(middle, right)) + matrix[row][col];
    }
};

*/

/*
class Solution {
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp(matrix.size() + 1,vector<int>(matrix[0].size() + 1, 0));
        
        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = 0; col < matrix[0].size(); col++) {
                
                if (col == 0) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col + 1]) + matrix[row][col];
                } 
                else if (col == matrix.size() - 1) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col - 1]) + matrix[row][col];
                } else {
                    dp[row][col] = min(dp[row + 1][col], min(dp[row + 1][col + 1], dp[row + 1][col - 1])) + matrix[row][col];
                }
            }
        }
        
        
        int minFallingSum = INT_MAX;
        
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, dp[0][startCol]);
        }
        return minFallingSum;
    }
};

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        vector<int> dp(matrix.size() + 1, 0);
        
            for (int row = matrix.size() - 1; row >= 0; row--) {

                vector<int> currentRow(matrix.size() + 1, 0);

                for (int col = 0; col < matrix.size(); col++) {

                    if (col == 0) {
                        currentRow[col] = min(dp[col], dp[col + 1]) + matrix[row][col];
                    } 
                    else if (col == matrix.size() - 1) {
                        currentRow[col] = min(dp[col], dp[col - 1]) + matrix[row][col];
                    } else {
                        currentRow[col] = min(dp[col], min(dp[col + 1], dp[col - 1])) + matrix[row][col];
                    }
                }

                dp = currentRow;
            }
        
        
        int minFallingSum = INT_MAX;
        
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, dp[startCol]);
        }
        return minFallingSum;
    }
};

