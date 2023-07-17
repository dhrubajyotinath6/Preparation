/*
Constraints:

2 <= nums.length <= 1000
0 <= nums[i] <= 500


*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        if(nums.size() == 2) return 2;
        if(nums.size() == 3) (nums[1] - nums[0] == nums[2] - nums[1]) ? 3 : 2;
        
        unordered_map<int,vector<int>> dp;
        int n = nums.size(), ans = 2;
        
        for(int right = 0; right < n; right++){
            for(int left = 0; left < right; left++){
                
                int diff = nums[right] - nums[left];
                
                if(dp.find(diff) == dp.end()){
                    dp[diff] = vector<int> (1001,1);
                }
                
                dp[diff][right] = max(dp[diff][right], dp[diff][left] + 1);
                ans = max(ans, dp[diff][right]);
            }
        }
        
        return ans;
    }
};