/*
Given a string, find the total number of palindromic substrings in it.
Please note we need to find the total number of substrings and not subsequences.

Example 1:

Input: "abdbca"
Output: 7
Explanation: Here are the palindromic substrings, "a", "b", "d", "b", "c", "a", "bdb".



Example 2:

Input: = "cddpd"
Output: 7
Explanation: Here are the palindromic substrings, "c", "d", "d", "p", "d", "dd", "dpd".


Example 3:

Input: = "pqr"
Output: 3
Explanation: Here are the palindromic substrings,"p", "q", "r"

*/

/*
This problem follows the Longest Palindromic Subsequence pattern, and can be easily converted to
Longest Palindromic Substring. The only difference is that instead of calculating
the longest palindromic substring, we will instead count all the palindromic substrings
*/

// BRUTE FORCE
class CPS
{
public:
    int findCPS(const string &st)
    {
        // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
        vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));
        int count = 0;

        // every string with one character is a palindrome
        for (int i = 0; i < st.length(); i++)
        {
            dp[i][i] = true;
            count++;
        }

        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--)
        {
            for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++)
            {
                if (st[startIndex] == st[endIndex])
                {
                    // if it's a two character string or the remaining string is a palindrome too
                    if (endIndex - startIndex == 1 || dp[startIndex + 1][endIndex - 1])
                    {
                        dp[startIndex][endIndex] = true;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

/*
The time and space complexity of the above algorithm is O(n^2),where ‘n’ is the length of the input string.

*/