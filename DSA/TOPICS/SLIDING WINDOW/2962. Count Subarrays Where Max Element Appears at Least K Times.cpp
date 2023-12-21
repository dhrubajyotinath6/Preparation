You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105


//https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/discuss/4384405/JavaC%2B%2BPython-Sliding-Window

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi = *max_element(nums.begin(), nums.end());
        
        long long ans = 0;
        long long cnt = 0;
        int windowStart = 0;
        
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            if(nums[windowEnd] == maxi) cnt++;
            
            while(cnt >= k){
                if(nums[windowStart] == maxi) cnt--;
                windowStart++;
            }
            
            ans += windowStart;
        }
        
        return ans;
    }
};