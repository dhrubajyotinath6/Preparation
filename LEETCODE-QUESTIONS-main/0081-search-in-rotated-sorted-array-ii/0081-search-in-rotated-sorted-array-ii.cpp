/*
To avoid duplicates, we can refer to the solution to Problem 15: 3 Sum, which is

      while (lo < hi && nums[lo] == nums[lo + 1])
        ++lo;
      while (lo < hi && nums[hi] == nums[hi - 1])
        --hi;
After this step, this problem becomes Problem 33: Search in Rotated Sorted Array.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size()-1;
        
        while(start <= end){
           
        //https://leetcode.com/problems/search-in-rotated-sorted-array-ii/solution/760943 -- very imp
          while (start < end && nums[start] == nums[start + 1]){
              start++;
          }           
      
          while (start < end && nums[end] == nums[end - 1]){
              end--;
          }              
            
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target) return true;
            
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
        return false;
    }
};