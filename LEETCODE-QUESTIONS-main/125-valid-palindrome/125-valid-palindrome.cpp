// https://leetcode.com/problems/valid-palindrome/solution/
class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j){
            
            while(i < j && !isalnum(s[i])) i++;
            
            while(i < j && !isalnum(s[j])) j--;
            
            if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        
        return true;
    }
};


/*
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

*/