class Solution {
public:
    // Return true if the character is a vowel (case-insensitive)
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        
        int start = 0, end = s.size()-1;
        
        while(start < end){
            
            while(start < s.size() && !isVowel(s[start])) start++;
            
            while(end >= 0 && !isVowel(s[end])) end--;
            
            if(start < end){
                swap(s[start++], s[end--]);
            }
        }
        
        return s;
    }
};



Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
