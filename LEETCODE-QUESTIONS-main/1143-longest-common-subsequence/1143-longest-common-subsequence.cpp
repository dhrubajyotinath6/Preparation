class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
       
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
    int maxLength = 0;
        
    for (int i = 1; i <= s1.length(); i++) {
      for (int j = 1; j <= s2.length(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

        maxLength = max(maxLength, dp[i][j]);
      }
    }
    return maxLength;
    }
};