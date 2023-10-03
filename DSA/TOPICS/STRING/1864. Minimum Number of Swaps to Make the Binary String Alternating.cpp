//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

Given a binary string s, return the minimum number of character swaps to make it alternating, 
or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal. 
For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Any two characters may be swapped, even if they are not adjacent.

 

Example 1:

Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.
Example 3:

Input: s = "1110"
Output: -1
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.


//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/discuss/1211118/JavaPython-Count-wrong-positions-O(N)-Easy-to-understand


class Solution {
    
    
    /*
    start = 1 - start;
    
    */
    
public:
    int countSwaps(string s, char start){
        
        int  wrongPos = 0;
        
        for(auto& ch : s){
            
            if(ch != start) wrongPos++;
    
            //cout << start << endl;
            int i = start - '0';
            i = 1 - i;
            start = '0' + i;           
        }
        
        return wrongPos/2;
    }
public:
    int minSwaps(string s) {
        
      int zero = 0, one = 0;
        
      for(auto& ch : s){
            if(ch == '0') zero++;
            else one++;
      }
        
      if(abs(zero - one) > 1) return -1;
      
      else if(zero > one) return countSwaps(s, '0');
      
      else if(one > zero) return countSwaps(s, '1');
        
      return min(countSwaps(s, '0'), countSwaps(s, '1'));
    }
};


