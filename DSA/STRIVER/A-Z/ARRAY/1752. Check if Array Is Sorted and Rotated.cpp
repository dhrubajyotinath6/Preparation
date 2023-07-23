Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length 
such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

class Solution {
public:
    bool check(vector<int>& nums) {
        
        
        /*
        for every pair (a,b) ->   a <= b always 
        a > b can happen at most once
        we hv to check the last and the first element too ->first element has to be greater or equal than last or first element less than last is ok but atMost should be false
        */
        
        bool atMost = false;
        
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i-1] > nums[i] && !atMost) atMost = true;           
           
            else if(nums[i-1] > nums[i] && atMost) return false;
            
        }
        
        // nums[nums.size()-1] > nums[0]  means nums is sorted , then  atMost should be false
        // if  nums[nums.size()-1] > nums[0]  is not , it means sorted array is rotate
        if(nums[nums.size()-1] > nums[0] && atMost) return false;
        
        return true;
    }
};