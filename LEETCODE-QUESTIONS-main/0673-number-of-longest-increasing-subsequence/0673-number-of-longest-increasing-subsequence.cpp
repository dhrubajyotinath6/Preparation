class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,1); // stores length of longest sequence till i-th position
        vector<int> count(n,1); // stores count of longest sequence of length lis[i]
        
        int maxLen = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                //possible lcs
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }else if(dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
            
            maxLen = max(maxLen, dp[i]);
        }
        
        cout << maxLen << endl;
        
        
        int noOfLis = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxLen) noOfLis += count[i];
        }
        
        return noOfLis;
    }
};



