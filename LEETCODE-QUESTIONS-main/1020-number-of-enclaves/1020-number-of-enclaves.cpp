/*
class Solution {
    
public:
    bool check(vector<vector<int>>& grid, int i, int j, int n, int m){
        
        //boundary checking
        if(i == 0 || i == n-1 || j == 0 || j == m-1) return true;
        
        //value 2 checking
        if((grid[i-1][j] == 2) || (grid[i+1][j] == 2) || (grid[i][j-1] == 2) || (grid[i][j+1] == 2)) return true;
        
        return false;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 1){
                    if(check(grid, i, j, n, m)){
                        grid[i][j] = 2;
                    }
                    else{
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};
*/
//the above solution will give wrong ans: see the below test case
/*
[
 [0,0,0,1,1,1,0,1,0,0],
 [1,1,0,0,0,1,0,1,1,1],
 [0,0,0,1,1,1,0,1,0,0],
 [0,1,1,0,0,0,1,0,1,0],
 [0,1,1,1,1,1,0,0,1,0],
 [0,0,1,0,1,1,1,1,0,1],
 [0,1,1,0,0,0,1,1,1,1],
 [0,0,1,0,0,1,0,1,0,1],
 [1,0,1,0,1,1,0,0,0,0],
 [0,0,0,0,1,1,0,0,0,1]
]


[
 [0,0,0,2,2,2,0,2,0,0],
 [2,2,0,0,0,2,0,2,2,2],
 [0,0,0,1,1,1,0,1,0,0],  --> this line
 [0,1,1,0,0,0,1,0,1,0],
 [0,1,1,1,1,1,0,0,1,0],
 [0,0,1,0,1,1,1,1,0,1],
 [0,1,1,0,0,0,1,1,1,1],
 [0,0,1,0,0,1,0,1,0,1],
 [1,0,1,0,1,1,0,0,0,0],
 [0,0,0,0,1,1,0,0,0,1]
]

*/

class Solution {
public:
    void dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visit[x][y]) {
            return;
        }

        visit[x][y] = true;
        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            dfs(x + dirx[i], y + diry[i], m, n, grid, visit);
        }
        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1 && !visit[i][0]) {
                dfs(i, 0, m, n, grid, visit);
            }
            // Last column.
            if (grid[i][n - 1] == 1 && !visit[i][n - 1]) {
                dfs(i, n - 1, m, n, grid, visit);
            }
        }

        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1 && !visit[0][i]) {
                dfs(0, i, m, n, grid, visit);
            }
            // Last row.
            if (grid[m - 1][i] == 1 && !visit[m - 1][i]) {
                dfs(m - 1, i, m, n, grid, visit);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visit[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};