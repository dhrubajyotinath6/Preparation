/*
Given an array of positive numbers and a positive number ‘k,’
find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
Example 2:

Input: [2, 3, 4, 1, 5], k=2
Output: 7
Explanation: Subarray with maximum sum is [3, 4].



  Subtract the element going out of the sliding window, i.e., subtract the first element of the window.
  Add the new element getting included in the sliding window, i.e., the element coming right
after the end of the window.

*/

// TC -> O(N)
// SC -> O(1)

static int findMaxSumSubArray(int k, const vector<int> &arr)
{
  int windowSum = 0, maxSum = 0;
  int windowStart = 0;

  for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
  {
    windowSum += arr[windowEnd]; // add the next element
    // slide the window, no need to slide if we've not hit the window size of 'k'
    if (windowEnd >= k - 1)
    {
      maxSum = max(maxSum, windowSum);
      windowSum -= arr[windowStart]; // subtract the element going out
      windowStart++;                 // slide the window ahead
    }
  }

  return maxSum;
}