//https://leetcode.com/problems/01-matrix/solution/

/*
For those who are asking why DP is done in two passes, in DP we can only use the values which are previously calculated. When we are parsing from top left and coming down to bottom right, we can only use the values of above and left because only those two values are precomputed, if we take right and down, those values are not yet computed, if we work with those values we will get suboptimal answer. For example take this test case,

	[1,0,1,1,0,0,1,0,0,1],
	[0,1,1,0,1,0,1,0,1,1],
	[0,0,1,0,1,0,0,1,0,0],
	[1,0,1,0,1,1,1,1,1,1],
	[0,1,0,1,1,0,0,0,0,1],
	[0,0,1,0,1,1,1,0,1,0],
	[0,1,0,1,0,1,0,0,1,1],
	[1,0,0,0,1,1,1,1,0,1],
	[1,1,1,1,1,1,1,0,1,0],
	[1,1,1,1,0,1,0,0,1,1]
the output should be

[
	[1,0,1,1,0,0,1,0,0,1],
	[0,1,1,0,1,0,1,0,1,1],
	[0,0,1,0,1,0,0,1,0,0],
	[1,0,1,0,1,1,1,1,1,1],
	[0,1,0,1,1,0,0,0,0,1],
	[0,0,1,0,1,1,1,0,1,0],
	[0,1,0,1,0,1,0,0,1,1],
	[1,0,0,0,1,2,1,1,0,1],
	[2,1,1,1,1,2,1,0,1,0],
	[3,2,2,1,0,1,0,0,1,1]
]
Now if you notice the left most element of the last row this value should be 3 as per out which is correct but if we try to parse all sides during the top left to bottom right parsing this happens,

Last two rows look like this

[2, 1, 1, 1, 1, 2, 1, 0, 1, 0]
[1, 1, 1, 1, 0, 1, 0, 0, 1, 1]
 ^
 I am talking about updating this one
On above it will see two on right it will see 1 (this is a false value, this value is not yet calculated), with this value we will incorrectly update this value to 2 instead of 3.

*/

/*
BFS

TC -> O(R*C)
SC -> O(R*C)

*/
/*
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};


tc -> O(r.c)
sc -> O(1)
