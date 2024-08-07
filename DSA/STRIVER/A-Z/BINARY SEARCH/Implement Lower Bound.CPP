/*
Floor in a Sorted Array

Given a sorted array arr[] of size N without duplicates, and given a value x. 
Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
Find the index of K(0-based indexing).

Example 1:

Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less 
than 0 is found. So output 
is "-1".
Example 2:

Input:
N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is
2 (i.e K = 2), whose index is 1(0-based 
indexing).
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
        int ans = -1;
        
        int low = 0, high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            
            if(arr[mid] == x){
                return mid;
            }
            else if(arr[mid] < x){
                ans = mid;
                low = mid + 1;
            }
            else{
                //arr[mid] > x
                high = mid - 1;
            }
            
        }
        
        return ans;
        
    }
};