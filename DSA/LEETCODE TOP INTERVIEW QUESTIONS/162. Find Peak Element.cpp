A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.





class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low = 0, high = nums.size()-1;
        
        while(low < high){
            int mid = (low + high)/2;
            
             if (nums[mid] > nums[mid + 1])
                high = mid;
             else
                low = mid + 1;
        }
        return low;
    }
};
/*
1 2 1 3 5 6 4

* low = 0, high = 6 -> mid = 3
  nums[mid] = 3, nums[mid + 1] = 5 --> mid < mid+1 --> so peak will lie to the right side and hence  
  low = mid + 1, high remain same
  
* 5, 6, 4  --> low = 4, high = 6, mid = 5 
  nums[mid] = 6, nums[mid+1] = 4  ---> mid > mid + 1 --> so peak lie at left side and hence 
  high = mid, low mean same
  
* 5, 6 --> low = 4, high = 5 --> mid = 4
  nums[mid] = 5, nums[mid + 1] = 6  --> mid < mid + 1 --> se peak at right side and hence 
  low = mid + 1 = 4 + 1 = 5, high means same ie 5
  
  Here loop breaks as soon as low == high
  
  the condition is low < high and not low <= high bcoz of below reason(since low == high , mid always be   same)
  6  --> low = 5, high = 5  --> mid = 5
  nums[mid] = 6, nums[mid+ 1] = 4 --> mid > mid + 1 --> so peak at left side and hence
  high = 5 , low = 5 --> same as previous steps 

  

*/