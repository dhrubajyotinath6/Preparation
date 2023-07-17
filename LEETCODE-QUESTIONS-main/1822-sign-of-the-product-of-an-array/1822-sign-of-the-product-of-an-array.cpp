/*
https://leetcode.com/problems/sign-of-the-product-of-an-array/discuss/1168505/C%2B%2B-Simple-easy-code

https://leetcode.com/problems/sign-of-the-product-of-an-array/discuss/1152555/Java-solution-0-ms-Seriously-why-we-need-2


*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int sign = 1;
        
        for(int num : nums){
            
            if(num == 0) return 0;
            
            else if(num < 0) sign = -sign;
        }
        
        return sign;
    }
};