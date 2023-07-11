Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. 

More formally, if you are on index i on the current row, you may move to either index i 
or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104


/*
If row == 0: This is the top of the triangle: it stays the same.

If col == 0: There is only one cell above, located at (row - 1, col).

If col == row: There is only one cell above, located at (row - 1, col - 1).

In all other cases: There are two cells above, located at (row - 1, col - 1) and (row - 1, col) .

*/


//Approach 1: Dynamic Programming (Bottom-up: In-place)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int row = 1; row < triangle.size(); row++){
            for(int col = 0; col <= row; col++){
                
                if(col == 0){
                    triangle[row][col] += triangle[row-1][col];
                } 
                else if(col == row){
                    triangle[row][col] += triangle[row-1][col-1];
                }else{
                    triangle[row][col] += min(triangle[row-1][col-1], triangle[row-1][col]);
                }
            }
        }
        
        return *min_element(begin(triangle.back()), end(triangle.back())); 
    }
};


/*
//Approach 2: Dynamic Programming (Bottom-up: Auxiliary Space)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<int> prevRow = triangle[0];
        
        for(int row = 1; row < triangle.size(); row++){
            vector<int> currRow;
            for(int col = 0; col <= row; col++){
                
                int ans = 0;
                
                if(col == 0){
                    ans = prevRow[col];
                } 
                else if(col == row){
                    ans = prevRow[col-1];
                }else{
                    ans = min(prevRow[col-1], prevRow[col]);
                }
                
                ans += triangle[row][col];
                
                currRow.push_back(ans);
            }
            
            prevRow = currRow;
        }
        
        return *min_element(begin(prevRow), end(prevRow)); 
    }
};
*/

//Approach 3: Dynamic Programming (Bottom-up: Flip Triangle Upside Down)
//u can also do this without changing the original matrix {triangle}
/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
         for (int row = triangle.size() - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                  
                int bestBelow = min(triangle[row+1][col], triangle[row+1][col+1]);
                triangle[row][col] += bestBelow;
            }        
         
         }  
        
        return triangle[0][0];
    }
};
*/