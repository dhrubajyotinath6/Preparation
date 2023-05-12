//https://leetcode.com/problems/flood-fill/

class Solution {
    
    void dfs(vector<vector<int>> &matrix, int row, int col, int oldColor, int newColor){
        
        if(row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size())
            return;
        
        if(matrix[row][col] != oldColor) return;
        
        matrix[row][col] = newColor;
        
        dfs(matrix, row, col + 1, oldColor, newColor);
        dfs(matrix, row + 1, col, oldColor, newColor);
        dfs(matrix, row , col - 1, oldColor, newColor);
        dfs(matrix, row - 1, col, oldColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] != color) dfs(image, sr, sc, image[sr][sc], color);
            
        return image;
    }
};