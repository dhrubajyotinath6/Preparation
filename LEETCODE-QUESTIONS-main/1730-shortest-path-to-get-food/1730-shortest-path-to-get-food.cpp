//https://leetcode.com/problems/shortest-path-to-get-food/discuss/1173550/why-Can't-we-apply-DFS-here-Can-somebody-explain!-Thanks

//https://leetcode.com/problems/shortest-path-to-get-food/discuss/1061312/C%2B%2B-or-Easy-to-Follow-Template-for-Interview


class Solution {
    
private:
    
    int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
public:
    
    int getFood(vector<vector<char>>& grid) {
        
        if (grid.empty() || grid[0].empty()) return -1; 
        
        int m = grid.size(), n = grid[0].size(); 
        
        queue<pair<int, int>> q; 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#') {
                    q.emplace(i, j);
                }
            }
        }
        
        int step = 0; 
        
        while (!q.empty()) {
            
            int s = q.size(); step++;
            
            for (int i = 0; i < s; i++) {
                
                auto [x, y] = q.front(); q.pop(); 
                
                for (int j = 0; j < 4; j++) {
                    
                    int nx = x + dirs[j][0], ny = y + dirs[j][1];
                    
                    if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                        
                        if (grid[nx][ny] == '*') return step;
                        
                        if (grid[nx][ny] == 'O') {
                            grid[nx][ny] = '&'; q.emplace(nx, ny);  // use '&' to mark the space that has been visited
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};