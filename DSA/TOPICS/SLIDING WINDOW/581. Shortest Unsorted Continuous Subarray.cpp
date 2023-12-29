Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105


class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        
        if(arr.size() <= 1) return 0;
        
        int low = 0, high = arr.size() - 1;
        // find the first number out of sorting order from the beginning
        while (low < arr.size() - 1 && arr[low] <= arr[low + 1]) {
          low++;
        }

        if (low == arr.size() - 1) {  // if the array is sorted
          return 0;
        }

        // find the first number out of sorting order from the end
        while (high > 0 && arr[high] >= arr[high - 1]) {
          high--;
        }

        // find the maximum and minimum of the subarray
        int subarrayMax = numeric_limits<int>::min(), subarrayMin = numeric_limits<int>::max();
        for (int k = low; k <= high; k++) {
          subarrayMax = max(subarrayMax, arr[k]);
          subarrayMin = min(subarrayMin, arr[k]);
        }

        // extend the subarray to include any number which is bigger than the minimum of 
        // the subarray
        while (low > 0 && arr[low - 1] > subarrayMin) {
          low--;
        }
        // extend the subarray to include any number which is smaller than the maximum of 
        // the subarray
        while (high < arr.size() - 1 && arr[high + 1] < subarrayMax) {
          high++;
        }

        return high - low + 1;
    }
};