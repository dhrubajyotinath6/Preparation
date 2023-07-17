//https://leetcode.com/problems/toeplitz-matrix/solution/
/*
Approach #1: Group by Category [Accepted]
Intuition and Algorithm

We ask what feature makes two coordinates (r1, c1) and (r2, c2) belong to the same diagonal?

It turns out two coordinates are on the same diagonal if and only if r1 - c1 == r2 - c2.

This leads to the following idea: remember the value of that diagonal as groups[r-c]. If we see a mismatch, the matrix is not Toeplitz; otherwise it is.

java code:

class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
    
        Map<Integer, Integer> groups = new HashMap();
        
        for (int r = 0; r < matrix.length; ++r) {
            for (int c = 0; c < matrix[0].length; ++c) {
            
                if (!groups.containsKey(r-c))
                    groups.put(r-c, matrix[r][c]);
                    
                else if (groups.get(r-c) != matrix[r][c])
                    return False;
            }
        }
        return True;
    }
}

Complexity Analysis

Time Complexity: O(M*N)O(M∗N). (Recall in the problem statement that M, NM,N are the number of rows and columns in matrix.)

Space Complexity: O(M+N)O(M+N).



*/

/*
Every element belongs to some diagonal, and it's previous element (if it exists) is it's top-left neighbor. Thus, for the square (r, c), we only need to check r == 0 OR c == 0 OR matrix[r-1][c-1] == matrix[r][c].

Complexity Analysis

Time Complexity: O(M*N)O(M∗N), as defined in the problem statement.

Space Complexity: O(1)O(1).

*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                
                if(r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c])
                    return false;
            }
        }
        return true;
    }
};