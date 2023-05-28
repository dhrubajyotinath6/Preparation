//https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

/*
Brian Kernighan’s Algorithm
Time Complexity: O(logn)

*/

/*
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int xorValue = start^goal;
        int count = 0;
        
        while(xorValue){
            xorValue &= xorValue-1;
            count++;
        }
        
        return count;
    }
};
*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};