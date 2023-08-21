Given an array of integers nums, find the maximum length of a subarray where the product 
of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

 

Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.


Example 2:

Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that will make the product 0 which is not positive.


Example 3:

Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109



//https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/1453511/Fully-explained-C%2B%2B-solution-or-Easy-to-understand

//https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/819292/C%2B%2B-One-pass-with-Explanation


/*
We shouldn't include 0 in the subarray. So we just handle each of the subarrays surrounded by 0s.
If there are even number of negative numbers in the subarray, the entire subarray has a positive product.

If there are odd number of negative numbers in the subarray, we have two candidates:
    From the first element of the subarray to the element before the last negative element
    From the next element of first negative element to the last element of the subarray.

*/

// Time: O(N)
// Space: O(1)

class Solution {
public:
    int getMaxLen(vector<int>& A) {
        
        int j = 0, N = A.size(), ans = 0;
        
        while (j < N) {
            
            int i = j, cnt = 0, first = -1, last = -1;
            
            while (j < N && A[j] != 0) {
                
                cnt += A[j] < 0;
                
                if (A[j] < 0) {
                    if (first == -1) first = j;
                    last = j;
                }
                ++j;
            }
            
            //if cnt is odd
            if (cnt % 2) ans = max({ ans, j - first - 1, last - i });            
            else ans = max(ans, j - i); // cnt is even
            
            while (j < N && A[j] == 0) ++j;
        }
        
        return ans;
    }
};

