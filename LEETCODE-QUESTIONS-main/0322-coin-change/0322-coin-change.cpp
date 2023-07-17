BEST SOLUTION --> GREEDY APPROACH

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amount + 1) );
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= amount; j++){
                dp[i][j] = numeric_limits<int>::max();
            }
        }
        
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= amount; j++){
               
                //exclude the coin
                if(i > 0){
                    dp[i][j] = dp[i-1][j];
                }
                
                 //include the coin
                if(j >=  coins[i]){
                    if(dp[i][j-coins[i]] != numeric_limits<int>::max()){
                        dp[i][j] = min(dp[i][j], dp[i][j-coins[i]] + 1);
                    }
                }
                
                
            }
        }
        
        return dp[n-1][amount] == numeric_limits<int>::max() ? -1:dp[n-1][amount];
        
    }
};
