Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.


class Solution {
    
public:
      int findLPSLength(const string &st) {
    // dp[i][j] stores the length of LPS from index 'i' to index 'j'
    vector<vector<int>> dp(st.length(), vector<int>(st.length()));

    // every sequence with one element is a palindrome of length 1
    for (int i = 0; i < st.length(); i++) {
      dp[i][i] = 1;
    }

    for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
      for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
        // case 1: elements at the beginning and the end are the same
        if (st[startIndex] == st[endIndex]) {
          dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1];
        } else { // case 2: skip one element either from the beginning or the end
          dp[startIndex][endIndex] =
              max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1]);
        }
      }
    }
    return dp[0][st.length() - 1];
  }
public:
    int minInsertions(string s) {
        return s.length() - findLPSLength(s);
    }
};