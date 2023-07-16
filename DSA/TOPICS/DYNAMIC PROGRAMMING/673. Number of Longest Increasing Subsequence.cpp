Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].


Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there 
are 5 increasing subsequences of length 1, so output 5.


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



