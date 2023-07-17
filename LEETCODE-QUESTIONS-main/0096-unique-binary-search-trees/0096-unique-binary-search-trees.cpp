/*
https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/C%2B%2BPython-5-Easy-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Catalan-O(N)
*/

class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
             for(int j = 1; j <= i; j++){
                  dp[i] += dp[j-1] * dp[i-j];
             }               
        }
           
        return dp[n];
    }
};

/*
for n = 2,

i=2,
dp[2] += dp[0]*dp[1]
dp[2] += dp[1]*dp[0]

--------------------

for n = 3,

i = 2,
dp[2] += dp[0]*dp[1]
dp[2] += dp[1]*dp[0]

for i = 3,
dp[3] += dp[0]*dp[2]
dp[3] += dp[1]*dp[1]
dp[3] += dp[2]*dp[0]
*/