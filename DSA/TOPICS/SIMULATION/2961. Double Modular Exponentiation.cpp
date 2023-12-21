You are given a 0-indexed 2D array variables where variables[i] = [ai, bi, ci, mi], and an integer target.

An index i is good if the following formula holds:

0 <= i < variables.length
((aibi % 10)ci) % mi == target
Return an array consisting of good indices in any order.

 

Example 1:

Input: variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
Output: [0,2]
Explanation: For each index i in the variables array:
1) For the index 0, variables[0] = [2,3,3,10], (23 % 10)3 % 10 = 2.
2) For the index 1, variables[1] = [3,3,3,1], (33 % 10)3 % 1 = 0.
3) For the index 2, variables[2] = [6,1,1,4], (61 % 10)1 % 4 = 2.
Therefore we return [0,2] as the answer.
Example 2:

Input: variables = [[39,3,1000,1000]], target = 17
Output: []
Explanation: For each index i in the variables array:
1) For the index 0, variables[0] = [39,3,1000,1000], (393 % 10)1000 % 1000 = 1.
Therefore we return [] as the answer.
 

Constraints:

1 <= variables.length <= 100
variables[i] == [ai, bi, ci, mi]
1 <= ai, bi, ci, mi <= 103
0 <= target <= 103




class Solution {
    
public:
    // Function to calculate (x^y % m)
    long long powerMod(long long x, long long y, long long m) {
        long long result = 1;

        x = x % m;

        while (y > 0) {
            if (y % 2 == 1) {
                result = (result * x) % m;
            }

            y = y >> 1; // equivalent to y /= 2
            x = (x * x) % m;
        }

        return result;
}
    
public:
    bool isGud(int i, vector<vector<int>>& variables, int target){
        
        int a = variables[i][0];
        int b = variables[i][1];
        int c = variables[i][2];
        int m = variables[i][3];
        
       // ((aibi % 10)ci) % mi == target
        
        long long result = powerMod(powerMod(a, b, 10), c, m);
        
        return result == target;
    }
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        
        vector<int> ans;
        
        int n = variables.size();
        
        for(int i = 0; i < n; i++){
            if(isGud(i, variables, target)) ans.push_back(i);
        }
        
        return ans;
    }
};