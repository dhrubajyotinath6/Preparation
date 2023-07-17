/*
We know that all positive numbers will be on multiple of 2 indexes(0,2,4..) 
and negatives will be on odd(1,3,5...) indexes.

1 <= |nums[i]| <= 105  -> so no Zero
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 0);
        
        int indexPos = 0, indexNeg = 1;
        
        for(auto num : nums){
            
            if(num > 0){
                ans[indexPos] = num;
                indexPos += 2;
            }
            else if(num < 0){
                ans[indexNeg] = num;
                indexNeg += 2;
            }
        }
        
        return ans;
    }
};