//https://leetcode.com/problems/decode-ways/solution/    -- very imp


A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters 
using the reverse of the mapping above (there may be multiple ways). 

For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).


/*
class Solution {
    
public:
    
    int help(int index, string &str, vector<int> &dp){
        
        if(dp[index] != -1) return dp[index];
            
        if(index == str.length()) return 1;
        
        if(str[index] == '0') return 0;
        
        if(index == str.length()-1) return 1;
        
        int ans = help(index+1, str, dp);
        
        if(stoi(str.substr(index,2)) <= 26){
            ans += help(index+2, str, dp);
        }
        
        dp[index] = ans;
        
        return ans;
    }
    
public:
    int numDecodings(string s) {
        
        vector<int> dp(s.size() + 1,-1);
        
        return help(0, s, dp);
    }
};
*/

/*
class Solution {
    
public:
    
    int help(int index, string &s, vector<int> &dp){
        
        //empty string can always be decoded
        dp[0] = 1;
        
        dp[1] = s[0] == '0' ? 0:1;
        
        for(int i = 2; i < dp.size(); i++){
            
            if(s[i-1] != '0'){
                dp[i] = dp[i-1];
            }
            
            int twoDigit = stoi(s.substr(i-2,2));
            
            if(twoDigit >= 10 && twoDigit <= 26){
                dp[i] += dp[i-2];
            }
        }
        
        return dp[s.length()];
    }
    
public:
    int numDecodings(string s) {
        
        vector<int> dp(s.size() + 1,-1);
        
        return help(0, s, dp);
    }
};
*/

/*
  n2  n1  temp
*/

class Solution {
    
public:
    
    int help(int index, string &s){
        
        //empty string can always be decoded
        int n1 = 1;
        int n2 = 1;
        
        for(int i = 1; i < s.size(); i++){
            
            //int temp; -> is wrong [check testcase '10']
            int temp = 0;
            
            if(s[i] != '0'){
                temp = n1;
            }
            
            int twoDigit = stoi(s.substr(i-1,2));
            
            if(twoDigit >= 10 && twoDigit <= 26){
                temp += n2;
            }
            
            //n2  n1  temp -> _  n2 n1
             n2 = n1;
            n1 = temp;
            
        }
        
        return n1;
    }
    
public:
    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;
        
        return help(0, s);
    }
};
