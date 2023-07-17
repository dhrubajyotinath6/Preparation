class Solution {
    int dfs(vector<vector<int>> &grid, int i, int j){
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        
        int area = 1;
        
        area += dfs(grid, i+1, j);
        area += dfs(grid, i-1, j);
        area += dfs(grid, i, j+1);
        area += dfs(grid, i, j-1);
        
        return area;
        
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea , dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
        
    }
};