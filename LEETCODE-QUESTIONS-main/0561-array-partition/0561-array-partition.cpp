//https://leetcode.com/problems/array-partition/solution/  -check other approach using Counting sort

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int maxSum = 0;
        for(int i = nums.size() - 2; i >= 0; i -= 2){
            maxSum += nums[i];
        }
        
        return maxSum;
    }
};