You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated 
such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, 
then 3 steps to the last index.


Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It is guaranteed that you can reach nums[n - 1].


class Solution {
public:
    int jump(vector<int>& jumps) {
        
       vector<int> dp(jumps.size());

    // initialize with infinity, except the first index which should be zero as we start 
    // from there
    for (int i = 1; i < jumps.size(); i++) {
      dp[i] = numeric_limits<int>::max();
    }

    for (int start = 0; start < jumps.size() - 1; start++) {
      for (int end = start + 1; end <= start + jumps[start] && end < jumps.size(); end++) {
        dp[end] = min(dp[end], dp[start] + 1);
      }
    }

    return dp[jumps.size() - 1];
    }
};

