class Solution {
    
public:
    bool findDivisonSum(vector<int> &nums, int divisor, int threshold){
        
        int res = 0;
        
        /*
        5/2 = 3
        */
        for(auto &num : nums){
            res += ceil((1.0*num)/divisor);
        }
        
        return res <= threshold;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int ans = -1;
        
        int low = 1, high = *max_element(nums.begin(), nums.end());
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(findDivisonSum(nums, mid, threshold)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};