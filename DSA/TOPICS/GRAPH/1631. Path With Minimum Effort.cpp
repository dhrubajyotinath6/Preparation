You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.


class Solution {
    
public:
    bool isValidCell(int i, int j, int row, int col){
        return i >= 0 && i <= row - 1 && j >= 0 && j <= col - 1;
    }
  
public:
    bool dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>> &vis, int row, int col, int mid, vector<vector<int>> &dir){     
        
        if(i == row - 1 && j == col - 1) return true;
        
        vis[i][j] = true;
        
        for(auto &direction : dir){
            int adjI = i + direction[0];
            int adjJ = j + direction[1];
            
            if(isValidCell(adjI, adjJ, row, col) && !vis[adjI][adjJ]){
                int currDiff = abs(heights[i][j] - heights[adjI][adjJ]);
                
                if(currDiff <= mid){
                    if(dfs(adjI, adjJ, heights, vis, row, col, mid, dir)) return true;
                }
            }
        }
        
        return false;
    }
    
public:
    bool possible(vector<vector<int>>& heights, int mid){
        
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> vis(row, vector<int>(col, 0));
        vector<vector<int>> dir {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        return dfs(0, 0, heights, vis, row, col, mid, dir);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int left = 0, right = 1e6;
        
        int ans = 1e6;
        
        while(left <= right){
            int mid = (left + right) >> 1;
            
            if(possible(heights, mid)){
                ans = mid;
                right =  mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
