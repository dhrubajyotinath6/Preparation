A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

 

Example 1:

Input: s = "0"
Output: true
Example 2:

Input: s = "e"
Output: false
Example 3:

Input: s = "."
Output: false
 

Constraints:

1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.



/*
( +-)   (numbers)   (.)     (numbers)             [ (e,E)    (+,-)     (number) ]
(opt)   (opt)       (opt)   ()          (opt)     [ ()       (opt)     ()       ]

                                

*/

class Solution {
public:
    bool isNumber(string s) {
        
        bool seenDigitFirst = false;
        bool seenExp = false;
        bool seenDot = false;
        bool seenDigitSecond = false;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            
            char curr = s[i];
            
            if(curr == '+' || curr == '-'){
                
                if(i == 0) continue;                
                if(i > 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
                
            }else if(isdigit(curr) && seenExp == false){
                    seenDigitFirst = true;
            }else if(curr == '.'){
                    
                if(seenDot == true || seenExp == true) return false;
                seenDot = true;
            }else if( curr == 'e' || curr == 'E'){
                if(seenExp == true || seenDigitFirst == false) return false;
                seenExp = true;
            }else if(isdigit(curr) && seenExp == true){
                seenDigitSecond  = true;
            }
            else{
                return false;
            }
            
            
        }
        
        if(seenExp == true) return seenDigitSecond;
        return seenDigitFirst;
    }
};