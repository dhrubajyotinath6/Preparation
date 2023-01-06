/*
https://leetcode.com/problems/string-to-integer-atoi/

Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.

+-12 => 0

*/

//WRONG CODE
class Solution {
public:
    int myAtoi(string s) {
        
        int negOrPos = 1;// 1 -> pos, -1 -> neg
        
        int res = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == ' ') continue;
            
            else if(s[i] == '-') negOrPos = -1;
            
            else if(isdigit(s[i])){
                
                int digit = s[i] - '0';
                
                // Check overflow and underflow conditions. 
                if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                    // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
                    return negOrPos == 1 ? INT_MAX : INT_MIN;
                }
                res = res*10 + digit;
            }
            else{
                if(s[i] != '+')
                    break;
            }
            
            
        }
        
        return res*negOrPos;
    }
};

//+-12 it would not work for above code


//CORRECT CODE
//https://leetcode.com/problems/string-to-integer-atoi/solution/  -- VERY IMP [READ IT]

/*
A maximum integer value that can be stored in an int data type is typically 2, 147, 483, 647, 
around 231 – 1, but is compiler dependent.

A minimum integer value that can be stored in an int data type is typically -2, 147, 483, 648, 
around -231, but is compiler dependent.

*/
class Solution {
public:
    int myAtoi(string input) {
        int sign = 1; 
        int result = 0; 
        int index = 0;
        int n = input.size();
        
        // Discard all spaces from the beginning of the input string.
        while (index < n && input[index] == ' ') { 
            index++; 
        }
        
        // sign = +1, if it's positive number, otherwise sign = -1. 
        if (index < n && input[index] == '+') {
            sign = 1;
            index++;
        } else if (index < n && input[index] == '-') {
            sign = -1;
            index++;
        }
        
        // Traverse next digits of input and stop if it is not a digit. 
        // End of string is also non-digit character.
        while (index < n && isdigit(input[index])) {
            int digit = input[index] - '0';

            // Check overflow and underflow conditions. 
            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            // Append current digit to the result.
            result = 10 * result + digit;
            index++;
        }
        
        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign * result;
    }
};