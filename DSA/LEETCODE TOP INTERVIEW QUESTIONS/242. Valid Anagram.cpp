Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

/*
https://leetcode.com/problems/valid-anagram/discuss/66519/2-C%2B%2B-Solutions-with-Explanations
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) return false;
        
        int n = s.length();
        int counts[26] = {0};
        
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
            
           /*
            if(i < 2){
                cout << endl;
                cout << s[i] << " " <<  counts[s[i] - 'a'] << endl;
                cout << t[i] << " " <<  counts[t[i] - 'a'] << endl;
            }
            
            a 1
            n -1

            n 0
            a 0
            */
            
        }
        
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
    
};