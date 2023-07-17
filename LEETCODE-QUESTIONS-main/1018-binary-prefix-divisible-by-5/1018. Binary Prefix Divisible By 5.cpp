//https://leetcode.com/problems/binary-prefix-divisible-by-5/discuss/265601/Detailed-Explanation-using-Modular-Arithmetic-O(n)

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        vector<bool> ans;
        int sum = 0;
        
        for(auto& num : nums){
            sum = (sum*2 + num)%5;
            ans.push_back(!sum);
        }
        
    return ans;
    }
};


/*
num = x+ y;

if rem = 0 , then we only care abt the current num
if rem != 0, then we only care abt the rem + current num

*/



 
