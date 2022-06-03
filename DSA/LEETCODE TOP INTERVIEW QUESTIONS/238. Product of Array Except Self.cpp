Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


/*
https://leetcode.com/problems/product-of-array-except-self/discuss/1597994/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Prefix-and-Suffix-product-O(1)-space-approach
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int pre = 1;
        int suff = 1;
        int n = nums.size();
        vector<int> ans(n,1);
        
        for(int i = 0; i <n; i++){
            ans[i] *= pre;
            pre *= nums[i];
            
            ans[n-1-i]  *= suff;
            suff *= nums[n-1-i];
        }
        return ans;
    }
};


  

  