/*
https://leetcode.com/problems/squares-of-a-sorted-array/

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number 
sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>squares(n);
        
        int left = 0, right = n-1, i = n-1;
        
        while(left <= right){
            
            int leftSquares = nums[left]*nums[left];
            int rightSquares = nums[right]*nums[right];
            
            if(leftSquares <= rightSquares){
                squares[i--] = rightSquares;
                right--;
            }
            
            else if(leftSquares > rightSquares){
                squares[i--] = leftSquares;
                left++;
            }
        }
        
        return squares;
    }
};