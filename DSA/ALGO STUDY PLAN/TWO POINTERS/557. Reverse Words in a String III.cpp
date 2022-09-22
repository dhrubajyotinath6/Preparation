/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"


Example 2:

Input: s = "God Ding"
Output: "doG gniD"

*/

class Solution {    
    void rev(string &s, int i, int j){
        
        while(i <= j){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++,j--;
        }        
    }
public:
    string reverseWords(string s) {
        
        int lastSpace = -1;        
        
        for(int i = 0; i <= s.size(); i++){
 
            if(s[i] == ' ' ||  i == s.size() ){
                
                int startIndex = lastSpace+1;
                int endIndex = i - 1;
                
                rev(s,startIndex,endIndex);
                
                lastSpace = i;
                
            }
            
           
        }
        
        return s;
    }
};