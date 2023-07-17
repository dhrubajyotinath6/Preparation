class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        
        int mini = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            mini = min(mini, nums[i]);
        }
        
        int sum = 0;
        
        while(mini > 0){
            sum += mini%10;
            mini /= 10;
        }
        
        return sum%2 == 0 ? 1:0;
    }
};
