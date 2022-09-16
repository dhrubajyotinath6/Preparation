/*
https://leetcode.com/problems/isomorphic-strings/

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/

// t.length == s.length

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        
        unordered_map<char,char> mppS_T;
        unordered_map<char,char> mppT_S;
        
        for(int i = 0; i < n; i++){
            
            char chS = s[i], chT = t[i];
            
            if(mppS_T.find(chS) == mppS_T.end() && mppT_S.find(chT) == mppT_S.end()){
                
                mppS_T[chS] =  chT;
                mppT_S[chT] =  chS;
            }
            
            else if(mppS_T.find(chS) != mppS_T.end() || mppT_S.find(chT) != mppT_S.end()){
                
                if(mppS_T[chS] != chT) return false;
                if(mppT_S[chT] != chS) return false;
            }            
            
        }
        
        return true;
    }
};

/*
Input
"badc"
"baba"

Output
true

Expected
false

*/
Here N is the length of each string (if the strings are not the same length, then they cannot be isomorphic).

Time Complexity: O(N). We process each character in both the strings exactly once 
                       to determine if the strings are isomorphic.
Space Complexity: O(1) since the size of the ASCII character set is fixed and the keys in our dictionary are all 
                       valid ASCII characters according to the problem statemen