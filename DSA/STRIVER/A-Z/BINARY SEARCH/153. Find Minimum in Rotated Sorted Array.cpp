/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/

/*
    SAME TO THIS "ROTATION COUNT" -> GROOKING
Given an array of numbers which is sorted in ascending order 
and is rotated ‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8]
Output: 2
Explanation: The array has been rotated 2 times.
*/

class Solution {
public:
    int findMin(vector<int>& arr) {
        
    int start = 0, end = arr.size() - 1;
        
    while (start < end) {
      int mid = start + (end - start) / 2;

      // if mid is greater than the next element
      if (mid < end && arr[mid] > arr[mid + 1]) { 
        return arr[mid + 1];
      }

      // if mid is smaller than the previous element
      if (mid > start && arr[mid - 1] > arr[mid]) { 
        return arr[mid];
      }

      if (arr[start] < arr[mid]) {  // left side is sorted, so the pivot is on right side
        start = mid + 1;
      } else {  // right side is sorted, so the pivot is on the left side
        end = mid - 1;
      }
    }

    return arr[0];  // the array has not been rotated
  }
    
};