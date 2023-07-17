/*
X^1 

1^1 = 0
0^1 = 1
https://leetcode.com/problems/complement-of-base-10-integer/solution/ -check other approach
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        
    if (n == 0) return 1;
        
    int todo = n, bit = 1;
        
    while (todo != 0) {
      // flip current bit
      n = n ^ bit;
      // prepare for the next run
      bit = bit << 1;
      todo = todo >> 1;
    }
    return n;
    }
};