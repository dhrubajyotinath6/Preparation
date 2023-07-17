class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        int maxi = INT_MIN, sum = 0;
        
        for(auto num : nums){
            
            sum += num;
            
            maxi = max(maxi,sum);
            
            if(sum < 0) sum = 0;
        }
        
       return maxi; 
    }
};