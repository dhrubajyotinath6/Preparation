/*
We can observe that, for any given 

n, the total number of layers is given by : (n+1)/2;
This works for both even and odd n.


*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int>(n));
        int count = 1;
        
        int top = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size()-1;
        
        int dir = 0;
        
        while(top <= down && left <= right){
            
            if(dir == 0){
                for(int i = left; i <= right; i++){
                    matrix[top][i] = count++;
                }
                top++;
            }
            
            else if(dir == 1){
                for(int i = top; i<=down; i++){
                    matrix[i][right] = count++;
                }
                right--;
            }
            
            else if(dir == 2){
                for(int i = right; i >= left; i--){
                    matrix[down][i] = count++;
                }
                down--;
            }
            
            else if(dir == 3){
                for(int i = down; i >= top; i--){
                    matrix[i][left] = count++;
                }
                left++;
            }
            
            dir++;
            dir = dir%4;
    }
        
     return matrix;   
        
    }
};