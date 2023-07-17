class Solution {
    
    void dfs(vector<vector<char>> &matrix, int i, int j){
        
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == '0') 
            return;
        
        matrix[i][j] = '0';
        
        dfs(matrix, i, j + 1);
        dfs(matrix, i + 1, j);
        dfs(matrix, i , j - 1);
        dfs(matrix, i - 1, j);
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        
        int count = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                
                if(grid[i][j] == '1'){
                    count++;
                    
                    dfs(grid,i,j);                    
                }
            }
        }
        
        return count;
    }
};