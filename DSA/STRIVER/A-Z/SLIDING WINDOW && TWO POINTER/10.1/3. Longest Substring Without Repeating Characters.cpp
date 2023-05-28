//https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int windowStart = 0, ans = 0;
        unordered_map<char,int> mpp;
        
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++){
            
            char ch = s[windowEnd];
            
            if(mpp.find(ch) != mpp.end()){
                windowStart = max(windowStart, mpp[ch] + 1);
            }
            
            mpp[ch] = windowEnd;
            
           ans = max(ans, windowEnd - windowStart + 1);
          
        }
        
        return ans;
    }
};

//abccab