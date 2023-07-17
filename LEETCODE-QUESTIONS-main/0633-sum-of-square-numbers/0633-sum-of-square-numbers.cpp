/*
 a*a + b*b = c
=>b*b = c - a*a

https://leetcode.com/problems/sum-of-square-numbers/solution/

Approach 5: Fermat Theorem
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long a = 0; a*a <= c; a++){
            double b = sqrt(c - a*a);
            if(b == (int)b){
                return true;
            }
        }
        return false;
    }
};