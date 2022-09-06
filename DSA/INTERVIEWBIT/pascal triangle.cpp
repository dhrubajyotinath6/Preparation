/*
Problem Description
 
 

Given numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
Constraints:
0 <= numRows <= 25

*/

vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int>> ans;
    
    for(int i = 0; i < A; i++){
        
        vector<int>temp(i+1);
        
        temp[0] = temp[i] = 1;
        
        //1, 3, 3, 1
        //i = 3
        for(int j = 1; j < i; j++){
            temp[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        
        ans.push_back(temp);
    }
    
    return ans;
}
