//https://leetcode.com/problems/valid-palindrome-ii/solution/
class Solution {
    
    bool checkPalindrome(string s, int i, int j){
        
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
public:
    bool validPalindrome(string s) {
        
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j){
            
            if(s[i] != s[j]){
                return (checkPalindrome(s,i,j-1) || checkPalindrome(s,i+1,j));
            }
            i++;
            j--;
        }
        
        return true;
    }
};
