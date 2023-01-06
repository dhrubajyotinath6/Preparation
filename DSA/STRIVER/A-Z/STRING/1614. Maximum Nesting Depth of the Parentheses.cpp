/*
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.
Example 2:

Input: s = "(1)+((2))+(((3)))"
Output: 3
*/

class Solution {
public:
    int maxDepth(string s) {
        
        int maxi = 0, count = 0;
        
        for(auto &ch : s){
            
            if(ch == '(') count++;
            if(ch == ')') count--;
            
            maxi = max(maxi, count);
        }
        return maxi;
    }
};