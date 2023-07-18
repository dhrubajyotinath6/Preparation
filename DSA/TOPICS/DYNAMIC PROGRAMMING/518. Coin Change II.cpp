You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.


Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000


class Solution {
    

public:
    int change(int total, vector<int>& denominations) {
        
    int n = denominations.size();
    vector<vector<int>> dp(n, vector<int>(total + 1));

    // populate the total=0 columns, as we will always have an empty set for zero total
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }
    // process all sub-arrays for all capacities

    for (int i = 0; i < n; i++) {
      for (int t = 1; t <= total; t++) {
        if (i > 0) {
          dp[i][t] = dp[i - 1][t];
        }
        if (t >= denominations[i]) {
          dp[i][t] += dp[i][t - denominations[i]];
        }
      }
    }

    // total combinations will be at the bottom-right corner.
    return dp[n - 1][total];

    }
};




