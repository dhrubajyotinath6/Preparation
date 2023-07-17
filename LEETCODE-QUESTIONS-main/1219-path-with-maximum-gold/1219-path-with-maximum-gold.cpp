/*
https://leetcode.com/problems/path-with-maximum-gold/discuss/398228/C%2B%2B-DFS
https://leetcode.com/problems/path-with-maximum-gold/discuss/398184/C%2B%2B-Short-DFS
https://leetcode.com/problems/path-with-maximum-gold/discuss/398388/C%2B%2BJavaPython-DFS-Backtracking-Clean-code-O(3k)

*/

/*
// PEPCODING SOLUTION
class Solution {
    
    void travelAndCollectGold(vector<vector<int>>& grid, int i, int j,  vector<vector<bool>> &visited, vector<int> &bag){
        
        if(i < 0 || j < 0 || i > grid.size() || j > grid[0].size() || grid[i][j] == 0 || visited[i][j] == true) return;
        
        visited[i][j] = true;
        bag.push_back(grid[i][j]);
        
        travelAndCollectGold(grid, i - 1, j, visited, bag);
        travelAndCollectGold(grid, i, j + 1, visited, bag);
        travelAndCollectGold(grid, i, j - 1, visited, bag);
        travelAndCollectGold(grid, i + 1, j, visited, bag);
        
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited( n, vector<bool>( m, false ) );

        
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] && visited[i][j] == false){
                    vector<int> bag;
                    travelAndCollectGold(grid, i, j, visited, bag);
                    
                    int sum = 0;
                    for(int val : bag) sum += val;
                    
                    if(sum > maxi) maxi = sum;
                }
                //if statement ends
            }
        }
        //double foe loop ends
        return maxi;
    }
};
*/


class Solution {
    
    int dfs(vector<vector<int>> &grid, int i, int j){

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) return 0;
        
        grid[i][j] = -grid[i][j];  // 3 -> -3   
        
        auto res = max({ dfs(grid, i + 1, j), dfs(grid, i, j + 1), dfs(grid, i - 1, j), dfs(grid, i, j - 1) });
        
        grid[i][j] = -grid[i][j];   // -3  ->  3
        
        return grid[i][j] + res;
        
    }
    
   
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxi = INT_MIN;
       
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 maxi = max(maxi, dfs(grid, i, j));
            }
        }
        return maxi;
    }
};

