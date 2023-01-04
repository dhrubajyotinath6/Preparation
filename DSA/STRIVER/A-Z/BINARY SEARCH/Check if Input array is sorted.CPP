/*
https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

Given an array arr[] of size N, check if it is sorted 
in non-decreasing order or not. 

Example 1:

Input:
N = 5
arr[] = {10, 20, 30, 40, 50}
Output: 1
Explanation: The given array is sorted.



Example 2:

Input:
N = 6
arr[] = {90, 80, 100, 70, 40, 30}
Output: 0
Explanation: The given array is not sorted.
*/


class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        // Array has one or no element
        if (n == 0 || n == 1) return true;

        for (int i = 1; i < n; i++)
            // Unsorted pair found
            if (arr[i - 1] > arr[i]) return false;

        // No unsorted pair found
        return true;
    }
};