/*
https://leetcode.com/problems/kth-largest-element-in-an-array/solution/  -- VERY  VERY IMP

***************************************************************************************************************
        Approach 2: Quickselect
This textbook algorthm has O(N) average time complexity. Like quicksort, it was developed by Tony Hoare, 
and is also known as Hoare's selection algorithm.

The approach is basically the same as for quicksort. For simplicity let's notice that 
kth largest element is the same as N - kth smallest element, hence one could implement 
kth smallest algorithm for this problem.

First one chooses a pivot, and defines its position in a sorted array in a linear time. 
This could be done with the help of partition algorithm.

To implement partition one moves along an array, compares each element with a pivot, 
and moves all elements smaller than pivot to the left of the pivot.

*************************************************************************************************************

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/

/*
Time complexity : O(Nlogk)
Space complexity : O(k)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue <int, vector<int>, greater<int>> minHeap;
        
        //if k = 2, i = 0,1
        for(int i = 0; i < nums.size(); i++){            
           minHeap.push(nums[i]); 
            
           if(minHeap.size() > k){
               minHeap.pop();
           }
        }
        
       return minHeap.top();
    }
};