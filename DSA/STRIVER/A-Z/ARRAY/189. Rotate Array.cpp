Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size() <= 1) return;
        
        k = k % nums.size();
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/*
Your input
[-1]
2

Output
[-1]

Expected
[-1]

*/


IF QUESTION IS 'TO THE LEFT BY K STEPS ' THEN


1  2  3  4  5  6  7 -->  3  4  5  6  7  1   2


'7  6   5   4   3'   "2   1"
 
int i = n - k

reverse(nums.begin(), nums.end());
reverse(nums.begin(), nums.begin() + i);
reverse(nums.begin() + i, nums.end());