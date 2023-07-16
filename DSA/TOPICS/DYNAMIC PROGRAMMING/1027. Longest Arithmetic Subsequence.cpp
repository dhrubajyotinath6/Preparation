Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no 
elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
 

Example 1:

Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].
 

Constraints:

2 <= nums.length <= 1000
0 <= nums[i] <= 500


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