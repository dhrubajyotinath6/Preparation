// https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/113787/C%2B%2B-with-explanation-O(n)-14ms

// https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/1704920/C%2B%2B-one-pass-time%3AO(n)-space%3AO(1)-(with-explanation)

/*
RX - XR
XL - LX

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
*/

class Solution {
public:
    bool canTransform(string start, string end) {
        
        int i = 0, j = 0;
        
        while(i < start.size() && j < end.size()){
            
            while(start[i] == 'X') i++;
            while(end[j] == 'X') j++;
            
            if(start[i] != end[j]) return false;
            if(start[i]=='R' && i>j) return false;
            if(start[i]=='L' && i<j) return false;
            
            i++; j++;
        }
        
        while(i<start.size() && start[i]=='X') i++;
        while(j<end.size() && end[j]=='X') j++;
        
        return i==j;
    }
};




--


Here I translate 'X' to '.' for understanding more easily.

start = "R..LR.R.L"
end   = ".RL..RRL."
From the above example, we can find some rules for 'L' and 'R':

1. "XL" to "LX": L only go left
2. "RX" to "XR": R only go right
3. L and R cannot change their order

For example, if we have "XXXXXXXL" and finally we may get the result "LXXXXXXX".

-----------------------------------------------------------------
We only need to check the "L" and "R" position in two string.
Using two pointer i and j to keep comparing:

skip 'X', make sure start[i] and end[j] is the same
'R' position in start is smaller than end
'L' position in start is larger than end
