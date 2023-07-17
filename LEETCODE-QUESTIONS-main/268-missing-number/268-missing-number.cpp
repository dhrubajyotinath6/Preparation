class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int xor1 = 0;
        
        for(int i = 1; i <= n; i++){
            xor1 ^= i;
        }
        
        int xor2 = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            xor2 ^= nums[i];
        }
        
        return xor1^xor2;
    }
};