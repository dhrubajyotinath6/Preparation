/*
https://leetcode.com/problems/two-sum-less-than-k/solution/

check approach 4 : counting sort

*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int ans = -1;
        int left = 0, right = nums.size()-1;
        
        while(left < right){
            int sum = nums[left] + nums[right];
            
            if(sum < k){
                ans = max(ans, sum);
                left++;
            }else{
                right--;
            }
        }
        
        return ans;
    }
};