//https://leetcode.com/problems/decode-ways/solution/    -- very imp


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
