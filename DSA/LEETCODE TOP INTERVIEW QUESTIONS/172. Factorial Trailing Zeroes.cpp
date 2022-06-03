Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0


/*
https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/Simple-CC%2B%2B-Solution-(with-detailed-explaination)
*/
class Solution {
public:
    int trailingZeroes(int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = 0;
        for(long long i=5; n/i>0; i*=5){
            result += (n/i);
        }
        return result; 
    }
};

