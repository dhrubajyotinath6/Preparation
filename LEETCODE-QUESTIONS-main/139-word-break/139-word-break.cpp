//https://leetcode.com/problems/word-break/solution/  --VERY IMP  APPROACH 1,2,4

/*
tc - O(N^3)
sc - O(N)
*/
/*
class Solution {
    
    bool f(string &s, set<string> &word_set, int start, vector<int> &dp){
        
        if(start == s.length()) return true;
        if(dp[start] != -1) return dp[start];
        
        for(int end = start + 1; end < s.length(); end++){
            if(word_set.find(s.substr(start, end - start + 1)) != word_set.end() && f(s,word_set,end+1, dp)){
                dp[start] = true;
                return true;
            }
        }
        dp[start] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return f(s,word_set,0,dp);
        
    }
};
*/

class Solution {

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;
        
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && word_set.find(s.substr(j , i - j)) != word_set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};

