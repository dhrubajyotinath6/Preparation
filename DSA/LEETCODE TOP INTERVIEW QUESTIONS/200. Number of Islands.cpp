Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water

//https://gist.github.com/SuryaPratapK/a494ad5194ea33ee83b343698c1fa98e
class Solution {
    void mark_current_island(vector<vector<char>> &matrix,int x,int y,int r,int c)
    {
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')  //Boundary case for matrix
            return;
        
        //Mark current cell as visited
        matrix[x][y] = '2';
        
        //Make recursive call in all 4 adjacent directions
        mark_current_island(matrix,x+1,y,r,c);  //DOWN
        mark_current_island(matrix,x,y+1,r,c);  //RIGHT
        mark_current_island(matrix,x-1,y,r,c);  //TOP
        mark_current_island(matrix,x,y-1,r,c);  //LEFT
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        //For FAST I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols = grid[0].size();
        
        //Iterate for all cells of the array
        int no_of_islands = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')
                {
                    mark_current_island(grid,i,j,rows,cols);
                    no_of_islands += 1;
                }
            }
        }
        return no_of_islands;
    }
};


