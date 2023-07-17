/*
https://leetcode.com/problems/ugly-number/discuss/69214/2-4-lines-every-language
Just divide by 2, 3 and 5 as often as possible and then check whether we arrived at 1. 
Also try divisor 4 if that makes the code simpler / less repetitive.
*/

class Solution {
public:
    bool isUgly(int n) {
        
        if(n <= 0) return false; 
        
        for(int i = 2; i <= 5; i++){
            while(n % i == 0){
                n = n / i;
            }
        }
        return n == 1;
    }
};