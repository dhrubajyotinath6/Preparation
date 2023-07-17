//https://leetcode.com/problems/interleaving-string/solution/

class Solution {
public:
    bool isInterleave(string m, string n, string p) {
            // dp[mIndex][nIndex] will be storing the result of string interleaving up
    // to p[0..mIndex+nIndex-1]
    vector<vector<bool>> dp(m.length() + 1, vector<bool>(n.length() + 1));

    // make sure if lengths of the strings add up
    if (m.length() + n.length() != p.length()) {
      return false;
    }

    for (int mIndex = 0; mIndex <= m.length(); mIndex++) {
      for (int nIndex = 0; nIndex <= n.length(); nIndex++) {
        // if 'm' and 'n' are empty, then 'p' must have been empty too.
        if (mIndex == 0 && nIndex == 0) {
          dp[mIndex][nIndex] = true;
        }
        // if 'm' is empty, we need to check the interleaving with 'n' only
        else if (mIndex == 0 && n[nIndex - 1] == p[mIndex + nIndex - 1]) {
          dp[mIndex][nIndex] = dp[mIndex][nIndex - 1];
        }
        // if 'n' is empty, we need to check the interleaving with 'm' only
        else if (nIndex == 0 && m[mIndex - 1] == p[mIndex + nIndex - 1]) {
          dp[mIndex][nIndex] = dp[mIndex - 1][nIndex];
        } else {
          // if the letter of 'm' and 'p' match, we take whatever is matched till 
          // mIndex-1
          if (mIndex > 0 && m[mIndex - 1] == p[mIndex + nIndex - 1]) {
            dp[mIndex][nIndex] = dp[mIndex - 1][nIndex];
          }
          // if the letter of 'n' and 'p' match, we take whatever is matched till 
          // nIndex-1 too note the '||', this is required when we have common letters
          if (nIndex > 0 && n[nIndex - 1] == p[mIndex + nIndex - 1]) {
            dp[mIndex][nIndex] = dp[mIndex][nIndex] || dp[mIndex][nIndex - 1];
          }
        }
      }
    }
    return dp[m.length()][n.length()];
    }
};