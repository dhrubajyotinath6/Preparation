//https://leetcode.com/problems/one-edit-distance/

Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.
 

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
 

Constraints:

0 <= s.length, t.length <= 104
s and t consist of lowercase letters, uppercase letters, and digits.



/*
abc , ab
ab  , abc
ab  , ac


abc  , abc -->false

*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        int n = s.length(), m = t.length();
        
        if(abs(n - m) > 1) return false;
        
        int i = 0, j = 0;
        
        while(i < n && j < m && s[i] == t[j]){
            i++;
            j++;
        }
        
        //if we reach end of both strings, it means both strings are same, so straight return false as same strings cannot be one edit distance apart.
        if(i == n && j == m) return false;
        
        /*
        characters are different 
        */
        
        //deletion is possible,   [ab'c'd  , ab'd']
        if(n > m){            
            return s.substr(i+1) == t.substr(j);
        }
        
        //insertion is possible [ab'd',  ab'c'd]
        else if(n < m){
            return s.substr(i) == t.substr(j+1);
        }
        //replace   [ab'c'd,  ab'f'd]
        else{
            return s.substr(i+1) == t.substr(j+1);
        }
        
        //never get executed
        return true;
 
    }
};

