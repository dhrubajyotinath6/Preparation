Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, 
    and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.



Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

/*
https://leetcode.com/problems/count-binary-substrings/discuss/1172569/Short-and-Easy-w-Explanation-and-Comments-or-Keeping-Consecutive-0s-and-1s-Count-or-Beats-100

class Solution {
public:
    int countBinarySubstrings(string &s) {
        
        int cur = 1, prev = 0;
        int ans = 0;
        
        for(int j = 1; j < s.length(); j++){
            
            if(s[j] != s[j-1]){
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
            else{
                cur++;
            }
        }
        ans += min(prev, cur);
        return ans;
    }
};
*/
class Solution {
public:
    
int countBinarySubstrings(string& s) {
    
  // we start from first character - so curConsecutive = 1
  int curConsecutive = 1, prevConsecutive = 0, ans = 0;
    
  for(int i = 1; i < size(s); i++) {
      
  	if(s[i] != s[i - 1]){ // whenever current & previous don't match
        
  		ans += min(prevConsecutive, curConsecutive), // number of substring formed is minimum of cur & prev count
  		prevConsecutive = curConsecutive,            // previous consecutive streak will become current consecutive and,
  		curConsecutive = 1;                          // current streak will be resetted
    }
  	else {
        curConsecutive++; 
    }
  		
  }
  // required to include count from last two groups of consecutive characters.
  ans += min(prevConsecutive, curConsecutive); 
    
  return ans;
}
};
