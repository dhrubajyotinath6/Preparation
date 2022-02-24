/*
https://youtube.com/playlist?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;  // if it is 1 or 2
                if(grid[i][j] == 2) rotten.push({i, j});  // if it is rotten
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){

            int k = rotten.size();
            cnt += k; 

            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();

                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue; //grid[nx][ny] != 1 -> In other words, if grid[nx][ny] == 0 || 2 continue;
                    grid[nx][ny] = 2;    // make it rotten   
                    rotten.push({nx, ny});  // then push it
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }
};