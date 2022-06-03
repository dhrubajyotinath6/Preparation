Given an array, rotate the array to the right by k steps, where k is non-negative.

 

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
        
        //For FAST I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        k %=nums.size();  
        
        // 1 2 3 4 5 ; k = 2 -> 4 5 1 2 3
        reverse(nums.begin(), nums.end()); //-> 5 4 3 2 1 
        reverse(nums.begin(), nums.begin()+k); //-> 4 5 3 2 1
        reverse(nums.begin()+k, nums.end()); //-> 4 5 1 2 3
    }
};