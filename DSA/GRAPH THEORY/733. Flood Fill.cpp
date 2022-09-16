/*
https://leetcode.com/problems/flood-fill/

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.


Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

*/

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