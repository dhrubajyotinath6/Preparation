/*
https://leetcode.com/problems/kth-largest-element-in-an-array/solution/  --VERY IMP FOR 0(1) SPACE SOLUTION

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