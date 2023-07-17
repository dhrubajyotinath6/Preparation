class Solution {
public:
    bool check(vector<int>& nums) {
        
        
        /*
        for every pair (a,b) ->   a <= b always 
        a > b can happen at most once
        we hv to check the last and the first element too ->first element has to be greater or equal than last or first element less than last is ok but atMost should be false
        */
        
        bool atMost = false;
        
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i-1] > nums[i] && !atMost) atMost = true;           
           
            else if(nums[i-1] > nums[i] && atMost) return false;
            
        }
        
        if(nums[nums.size()-1] > nums[0] && atMost) return false;
        
        return true;
    }
};