/*
Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to '7' is [5, 2].
Example 2:

Input: [2, 1, 5, 2, 8], S=7
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
Example 3:

Input: [3, 4, 1, 1, 6], S=8
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1]
or [1, 1, 6].

*/

// TC -> O(N)
// SC -> O(1)

/*
The time complexity of the above algorithm will be O(N).
The outer for loop runs for all elements, and the inner while loop processes each element only once;
therefore, the time complexity of the algorithm will be O(N+N),
which is asymptotically equivalent to O(N).

*/

static int findMinSubArray(int S, const vector<int> &arr)
{
  int windowSum = 0, minLength = numeric_limits<int>::max();
  int windowStart = 0;

  for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
  {
    windowSum += arr[windowEnd]; // add the next element
    // shrink the window as small as possible until the 'windowSum' is smaller than 'S'
    while (windowSum >= S)
    {
      minLength = min(minLength, windowEnd - windowStart + 1);
      windowSum -= arr[windowStart]; // subtract the element going out
      windowStart++;                 // slide the window ahead
    }
  }

  return minLength == numeric_limits<int>::max() ? 0 : minLength;
}
