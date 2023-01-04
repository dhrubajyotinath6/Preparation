/*
Problem Statement: You are given a sorted array containing N integers and a number X, 
you have to find the occurrences of X in the given array.

Examples:

Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array so it is our answer.
*/

// https://takeuforward.org/data-structure/count-occurrences-in-sorted-array/

#include <iostream>

#include <iostream>

using namespace std;

int binary(int arr[], int n, int x) {
  int start = 0;
  int end = n - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (arr[mid] == x) {
      return m;
    } else if (arr[mid] < x) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

int count(int arr[], int n, int x) {
  
  int idx = binary(arr, n, x);

  // if X does not exist return 0;
  if (idx == -1) {
    return 0;
  }

  int k = 1;
  int left = idx - 1;

  // check left half for X
  while (left >= 0 && arr[left] == x) {
    k++;
    left--;
  }
  // check right half for X
  int right = idx + 1;
  while (right < n && arr[right] == x) {
    k++;
    right++;
  }

  return k;
}

int main() {
  int n = 7;
  int x = 3;
  int arr[] = {2,2,3,3,3,3,4};
    
  int ans = count(arr, n, x);
  cout <<x<<" occurs "<<ans<<" times in the array" << endl;
}