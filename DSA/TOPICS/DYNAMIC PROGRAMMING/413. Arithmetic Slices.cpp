An integer array is called arithmetic if it consists of at least three elements 
and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.


Example 2:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000



/*
a, b, c, d -> x
a, b, c, d, e -> x+1

*/
/*
// Better Brute Force
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int count = 0;
        
        for (int s = 0; s < nums.size() - 2; s++) {
            
            int d = nums[s + 1] - nums[s];
            
            for (int e = s + 2; e < nums.size(); e++) {
                if (nums[e] - nums[e - 1] == d)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};
*/

/*
//Recursion
class Solution {
    int sum = 0;
public:
    int numberOfArithmeticSlices(vector<int>& nums) {       
       
        slices(nums, nums.size() - 1);
        return sum;
    }
    
public:
    int slices(vector<int>& nums, int i) {
        
        if (i < 2)
            return 0;
        int ap = 0;
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            ap = 1 + slices(nums, i - 1);
            sum += ap;
        } else
            slices(nums, i - 1);
        return ap;
    }
};
*/

/*
//Dynamic Programming

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<int> dp(nums.size());
        int sum = 0;
        
        for (int i = 2; i < dp.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;          

    }
};

*/


//Constant Space Dynamic Programming
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int dp = 0;
        int sum = 0;
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp = 1 + dp;
                sum += dp;
            } else
                dp = 0;
        }
        return sum;       

    }
};



