//https://leetcode.com/problems/number-of-distinct-islands/

class Solution {
    
public:
    void traverseIslandDFS(vector<vector<int>> &matrix, vector<vector<bool>> &visited,
                                  int x, int y, string &islandTraversal, string direction){
        
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
            return; // return if it is not a valid cell
        if (matrix[x][y] == 0 || visited[x][y])
            return; // return if it is a water cell or is visited

        visited[x][y] = true; // mark the cell visited

        islandTraversal += direction;
        // recursively visit all neighboring cells (horizontally & vertically)
        traverseIslandDFS(matrix, visited, x + 1, y, islandTraversal, "D"); // down
        traverseIslandDFS(matrix, visited, x - 1, y, islandTraversal, "U"); // up
        traverseIslandDFS(matrix, visited, x, y + 1, islandTraversal, "R"); // right
        traverseIslandDFS(matrix, visited, x, y - 1, islandTraversal, "L"); // left

        islandTraversal += "B"; // back
    }
public:
    int numDistinctIslands(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        unordered_set<string> islandsSet;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 1 && !visited[i][j])
                { // if the cell is land and not visited
                    string islandTraversal;
                    traverseIslandDFS(matrix, visited, i, j, islandTraversal, "O"); // Origin
                    islandsSet.insert(islandTraversal);
                }
            }
        }
        return islandsSet.size();
    }
};