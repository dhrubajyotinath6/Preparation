Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.  *******************************************************
0 <= goal <= nums.length


//https://leetcode.com/problems/binary-subarrays-with-sum/discuss/186683/C%2B%2BJavaPython-Sliding-Window-O(1)-Space

/*
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        
        int prefixSum = 0, cnt = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            prefixSum += nums[i];
            
            cnt += mpp[prefixSum - goal];
            
            mpp[prefixSum]++;
        }
        
        return cnt;
    }
};
*/

class Solution {
    
public:
    int atMost(vector<int> &nums, int goal){
        
        if(goal < 0) return 0;
        
        int windowStart = 0, cnt = 0;
        
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            goal -= nums[windowEnd];
            
            while(goal < 0){
                goal += nums[windowStart++];
            }
            
            cnt += (windowEnd - windowStart + 1);
        }
        
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) { 
       return atMost(nums, goal) - atMost(nums, goal -1);
    }
};