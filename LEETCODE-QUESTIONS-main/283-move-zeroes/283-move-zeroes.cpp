class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i = 0;
        
        for(int j = 0; j < nums.size(); j++){
            
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
        }
        
        for(int j = i; j < nums.size(); j++){
            nums[j] = 0;
        }
        
    }
};