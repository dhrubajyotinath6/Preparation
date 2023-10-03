Given an integer n, count the total number of digit 1 appearing in all non-negative integers 
less than or equal to n.

 

Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 109

//https://leetcode.com/problems/number-of-digit-one/submissions/

class Solution {
public:
    int countDigitOne(int n){
        
    int countr = 0;
        
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
        
    return countr;
}
};