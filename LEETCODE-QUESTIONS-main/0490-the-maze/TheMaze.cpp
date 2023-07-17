class Solution {
    
public:
    bool dfs(vector<vector<int>> &maze, vector<int>&start, vector<int>&dest, vector<vector<int>> &visit){
        if(visit[start[0]][start[1]] == 1) return false;
        
        if (start[0] == dest[0] && start[1] == dest[1]) return true;              
        visit[start[0]][start[1]] = 1;
        
        int r = start[1] + 1, l = start[1] -1, u = start[0]-1, d = start[0]+1;
        
        //right
        while(r < maze[0].size() && maze[start[0]][r] == 0) r++;
        vector<int> startR{start[0], r-1};
        if(dfs(maze, startR, dest, visit)) return true;
        
        //left
        while (l >= 0 && maze[start[0]][l] == 0)  l--; 
        vector<int> startL{start[0], l + 1};
        if (dfs(maze, startL, dest, visit)) return true;
          
        //up
        while (u >= 0 && maze[u][start[1]] == 0) u--;
        vector<int> startU{u + 1, start[1]};
        if (dfs(maze, startU, dest, visit)) return true;
        
        //down
        while (d < maze.size() && maze[d][start[1]] == 0) d++;
        vector<int> startD{d - 1, start[1]};
        if (dfs(maze, startD, dest, visit)) return true;
        
        return false;
    }
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        vector<vector<int>> visit(maze.size(), vector<int>(maze[0].size()));
        return dfs(maze, start, destination, visit);
    }
};
