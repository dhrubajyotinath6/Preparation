Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

//vector<vector<uint>> dp(n, vector<uint>(m));    ----  IMP

class Solution {
    
public:
     int findSPMCount(string &str, string &pat) {
    // every empty pattern has one match
    if (pat.length() == 0) {
      return 1;
    }

    if (str.length() == 0 || pat.length() > str.length()) {
      return 0;
    }

    // dp[strIndex][patIndex] will be storing the count of SPM up to
    // str[0..strIndex-1][0..patIndex-1]
    int n = str.length() + 1, m = pat.length() + 1;
    vector<vector<uint>> dp(n, vector<uint>(m));     // imp line

    // for the empty pattern, we have one matching
    for (int i = 0; i <= str.length(); i++) {
      dp[i][0] = 1;
    }

    for (int strIndex = 1; strIndex <= str.length(); strIndex++) {
      for (int patIndex = 1; patIndex <= pat.length(); patIndex++) {
        if (str[strIndex - 1] == pat[patIndex - 1]) {
          dp[strIndex][patIndex] = dp[strIndex - 1][patIndex - 1];
        }
        dp[strIndex][patIndex] += dp[strIndex - 1][patIndex];
      }
    }

    return dp[str.length()][pat.length()];
  }
public:
    int numDistinct(string s, string t) {
        
        int ans = findSPMCount(s, t);
        return ans;
    }
};





