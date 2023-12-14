You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

 

Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
 

Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.


class Solution {
    
public:
    void put(vector<vector<int>>& mat, unordered_map<int, vector<int>> &mpp){
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                
                vector<int> indexes {i,j};
                mpp[mat[i][j]] = indexes;
            }
        }
    }
    
public:
    vector<int> find(int val, unordered_map<int, vector<int>> &mpp){
        return mpp[val];
    }
    
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int noOfRows = mat.size(),  noOfCols = mat[0].size();
        vector<int> rows(noOfRows,0),  cols(noOfCols, 0);
        
        unordered_map<int, vector<int>> mpp;
        put(mat, mpp);
        
        for(int i = 0; i < arr.size(); i++){
            
            int val = arr[i];
            
            vector<int> rowCol = find(val, mpp);
            
            rows[rowCol[0]] += 1;
            cols[rowCol[1]] += 1;
            
            if(rows[rowCol[0]] == noOfCols || cols[rowCol[1]] == noOfRows){
                return i;
            }
            
            
        }
        
        return -1;
    }
};