Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1

/*
https://leetcode.com/problems/power-of-four/discuss/80455/One-of-my-favorite-tricks
https://leetcode.com/problems/power-of-four/discuss/80460/1-line-C%2B%2B-solution-without-confusing-bit-manipulations
https://leetcode.com/problems/power-of-four/discuss/80456/O(1)-one-line-solution-without-loops
*/
// class Solution {
// public:
//     bool isPowerOfFour(int num) {
        
//    // if(num == 1) return true;
       
//     return  (num > 0 && (num & 1) == 0 && (num - 1) % 3 == 0);  -->check 10
        
//     //for num & 1 check https://stackoverflow.com/questions/14905643/what-does-this-boolean-number-1-0-mean
//     }
// };

class Solution {
public:
    bool isPowerOfFour(int num) {       
       
    return  (num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0);
    
        //https://tianrunhe.wordpress.com/2012/03/09/explain-n-n-1-0/ (num & (num - 1)) == 0
    
    }
};