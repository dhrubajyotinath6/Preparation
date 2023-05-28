//https://leetcode.com/problems/power-of-two/

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

//https://leetcode.com/problems/power-of-two/discuss/1638961/C%2B%2BPython-Simple-Solutions-w-Explanation-or-All-Possible-Solutions-Explained
class Solution {
public:
    bool isPowerOfTwo(int num) {
         return  num > 0 && (num & (num - 1)) == 0;
    }
};

