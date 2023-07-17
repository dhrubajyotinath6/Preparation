/*
https://leetcode.com/problems/diagonal-traverse/discuss/581868/Easy-Python-NO-DIRECTION-CHECKING/1022170

*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> res(n + m, vector<int>());        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res[i+j].push_back(mat[i][j]);
            }
        }
        
        for(int i = 0; i < res.size(); i++){
            if(i % 2 == 0){
                reverse(res[i].begin(), res[i].end());
            }
            
            for(int j = 0; j < res[i].size(); j++){
                ans.push_back(res[i][j]);
            }
        }
        return ans;
    }
};
