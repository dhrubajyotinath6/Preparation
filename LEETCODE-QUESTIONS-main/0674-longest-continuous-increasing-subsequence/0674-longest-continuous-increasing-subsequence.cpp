class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        
        int maxi = INT_MIN, curr = 1;
        
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i-1] < nums[i]){
                curr++;
            }
            else{
                curr = 1;
            }
            
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};