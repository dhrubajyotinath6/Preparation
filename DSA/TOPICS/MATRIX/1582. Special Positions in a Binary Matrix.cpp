Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        //3                        4
        int noOfRows = mat.size(), noOfCols = mat[0].size();
        
        vector<int> zerosRows(noOfRows,0),  zerosCols(noOfCols, 0);
        
        for(int i = 0; i < noOfRows; i++){
            for(int j = 0; j < noOfCols; j++){
                
                int isItOne = (mat[i][j] == 1 ? 1:0);
                
                zerosRows[i] += isItOne;
                zerosCols[j] += isItOne;
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < noOfRows; i++){
            for(int j = 0; j < noOfCols; j++){
                
                if(mat[i][j] == 1 && zerosRows[i] == 1 && zerosCols[j] == 1) cnt++;
            }
        }
        
        return cnt;
    }
};