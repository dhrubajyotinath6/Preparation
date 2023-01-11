//https://leetcode.com/problems/single-element-in-a-sorted-array/

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

1       1       2       3       3       4       4       8       8
0       1       2       3       4       5       6       7       8

first half -> 1st number appears at EVEN index
     
2nd half  ->  1st  number appears at ODD index
*/

int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2; 
        while(low <= high) {
            int mid = (low + high) >> 1; 
            if(nums[mid] == nums[mid^1]) {
                low = mid + 1; 
            } 
            else {
                high = mid - 1; 
            }
        }
        return nums[low]; 
    }
    
    /*
    3^1 =  2
    
    011
      1
-----------
    010
 
 5^1 = 4
 
 101
   1
 ----
 100
    
 ================================   
    
    4^1 = 5
    
    100
      1
 -----------
    101
    */
