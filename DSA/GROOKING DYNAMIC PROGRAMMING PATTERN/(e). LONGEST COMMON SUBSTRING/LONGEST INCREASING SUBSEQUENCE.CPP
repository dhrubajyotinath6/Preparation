
********************************************************************************************************
/*
https://leetcode.com/problems/longest-increasing-subsequence/solution/

https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!

*/
***********************************************************************************************************
/*

Given a number sequence, find the length of its Longest Increasing Subsequence (LIS). 
In an increasing subsequence, all the elements are in increasing order (from lowest to highest).

Example 1:

Input: {4,2,3,6,10,1,12}
Output: 5
Explanation: The LIS is {2,3,6,10,12}.
Example 1:

Input: {-4,10,3,7,15}
Output: 4
Explanation: The LIS is {-4,3,7,15}.

Basic Solution

A basic brute-force solution could be to try all the subsequences of the given number sequence. 
We can process one number at a time, so we have two options at any step:

If the current number is greater than the previous number that we included, we can increment our count 
and make a recursive call for the remaining array.
We can skip the current number to make a recursive call for the remaining array.
The length of the longest increasing subsequence will be the maximum number returned by the two recurse 
calls from the above two options.

*/

