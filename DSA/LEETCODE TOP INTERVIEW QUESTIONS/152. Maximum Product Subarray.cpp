//https://leetcode.com/problems/maximum-product-subarray/solution/   --VERY IMP

Given an integer array nums, find a contiguous non-empty subarray within the array 
that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        
        int res = max_so_far;
        
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            
            int temp = max(curr, max(max_so_far*curr, min_so_far*curr));
            
            min_so_far = min(curr, min(max_so_far*curr, min_so_far*curr)); 
            
            max_so_far = temp;
            
            res = max(res, max_so_far);
        }
        
        return res;
    }
};

/*

tc - O(N)
sc - O(1)
*/