//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/

//https://leetcode.com/problems/number-of-1-bits/solution/ -- REFER THIS ALSO
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        
            while(n){
                
                n = n&(n-1);
                count++;
            }
        
            return count;
    }
};