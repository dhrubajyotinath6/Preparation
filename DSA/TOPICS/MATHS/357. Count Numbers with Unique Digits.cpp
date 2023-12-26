Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

 

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
Example 2:

Input: n = 0
Output: 1
 

Constraints:

0 <= n <= 8

/*
f(0)  = 1;
f(1)  = 10;
f(2)  = 9 * 9
f(3)  = 9 * 9 * 8
f(4)  = 9 * 9 * 8 * 7
f(5)  = 9 * 9 * 8 * 7 * 6
f(6)  = 9 * 9 * 8 * 7 * 6 * 5
f(7)  = 9 * 9 * 8 * 7 * 6 * 5 * 4
f(8)  = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3
f(9)  = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2
f(10) = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1

f(11) = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 * 0 = 0

if(n == 4){
 ans =  f(1) + f(2) + f(3)   + f(4)
     =  10   + 9*9  + 9*9*8  + 9*9*8*7
     =  10   + x*y  +  x*y   +  x*y
}



*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n == 0) return 1;
        if(n == 1) return 10;
        if(n >= 11) return 0;
        
        int ans = 10;
        
        int x = 9, y = 9;
        
        for(int i = 2; i <= n; i++){
            
            int z = x*y;
            ans += z;
            
            x = z;
            y -= 1;
            
        }
        
        return ans;
    }
};

// sc - O(1)
// tc - in the for loop, n maximum value can be 10 only, so tc is O(1)