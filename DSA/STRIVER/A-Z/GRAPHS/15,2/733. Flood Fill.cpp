//https://leetcode.com/problems/flood-fill/


An image is represented by an m x n integer grid image where image[i][j] 
represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image 
starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally 
to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.



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