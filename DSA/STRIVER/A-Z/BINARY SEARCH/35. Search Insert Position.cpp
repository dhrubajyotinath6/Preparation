/*
https://leetcode.com/problems/search-insert-position/

Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(nums.size() <= 0) return 0;
        if(nums.size() == 1) return nums[0] >= target ? 0 : 1;
        
        if(nums[0] > target) return 0;
        if(nums[nums.size()-1] < target) return nums.size();
        
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] < target){
               //1 3 5 6 , insert 4
                low = mid + 1;
            } 
            
            else if(nums[mid] > target){
                //1 3 5 6 , insert 4
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

  ******** OR *********

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(nums.size() <= 0) return 0;
        if(nums.size() == 1) return nums[0] >= target ? 0 : 1;
        
        int low = 0, high = nums.size();
        
        while(low < high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] < target) low = mid + 1;
            
            else if(nums[mid] > target) high = mid;
        }
        
        return low;
    }
};

/*
Your input
[1]
0

Output
0

Expected
0

--------
Input
[1]
1

Output
1

Expected
0

*/

