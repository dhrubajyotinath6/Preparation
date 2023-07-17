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