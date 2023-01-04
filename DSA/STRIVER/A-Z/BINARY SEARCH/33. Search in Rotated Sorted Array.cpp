/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size()-1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[start] <= nums[mid]){
                
                if(target >= nums[start] && target < nums[mid]){
                     end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                
                if(target > nums[mid] && target <= nums[end]){
                    start =  mid + 1;
                }
                else{
                    end = mid - 1;
                }
                
            }
            
        }
        return -1;
    }
};