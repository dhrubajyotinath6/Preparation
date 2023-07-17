/*
Algorithm
 Calculate the maximum subarray maxSum using Kadane's algorithm.
 Calculate the minimum subarray minSum using Kadane's algorithm, by using Math.min() instead of Math.max().
 Calculate the sum of all the elements in nums, sum
 If minSum == sum return maxSum, otherwise return max(maxSum, sum - minSum).


*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int cur_max = 0, cur_min = 0, sum = 0, max_sum = nums[0], min_sum = nums[0];
        
        for(auto& num : nums){
            
            cur_max = max(cur_max, 0) + num;
            max_sum = max(max_sum, cur_max);
            
            cur_min = min(cur_min, 0) + num;
            min_sum = min(min_sum, cur_min);
            
            sum += num;
            
        }
        
     /*
     sum == min_sum -> means all numbers are -ve
     
     */
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
        /*
        return max(max_sum, sum - min_sum);
        
        Input
        [-3,-2,-3]
        Output
        0
        Expected
        -2
        
        */
    }
};
