/*
Given a string, find the length of its Longest Palindromic Substring (LPS).
In a palindromic string, elements read the same backward and forward.

Example 1:

Input: "abdbca"
Output: 3
Explanation: LPS is "bdb".


Example 2:

Input: = "cddpd"
Output: 3
Explanation: LPS is "dpd".


Example 3:

Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".

*/

/*
The brute-force solution will be to try all the substrings of the given string.
We can start processing from the beginning and the end of the string.
So at any step, we will have two options:

    If the element at the beginning and the end are the same, we make a recursive call to check
if the remaining substring is also a palindrome. If so, the substring is a palindrome from
beginning to the end.

    We will skip either the element from the beginning or the end to make two recursive calls for the
remaining substring. The length of LPS would be the maximum of these two recursive calls.


*/

// BRUTE FORCE
class LPS
{

public:
    int findLPSLength(const string &st)
    {
        return findLPSLengthRecursive(st, 0, st.length() - 1);
    }

private:
    int findLPSLengthRecursive(const string &st, int startIndex, int endIndex)
    {
        if (startIndex > endIndex)
        {
            return 0;
        }

        // every string with one character is a palindrome
        if (startIndex == endIndex)
        {
            return 1;
        }

        int c1 = 0;
        // case 1: elements at the beginning and the end are the same
        if (st[startIndex] == st[endIndex])
        {
            int remainingLength = endIndex - startIndex - 1;
            if (remainingLength == findLPSLengthRecursive(st, startIndex + 1, endIndex - 1))
            {
                c1 = remainingLength + 2;
            }
        }

        // case 2: skip one character either from the beginning or the end
        int c2 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
        int c3 = findLPSLengthRecursive(st, startIndex, endIndex - 1);
        return max(c1, max(c2, c3));
    }
};

// Top-down Dynamic Programming with Memoization
class LPS
{

public:
    int findLPSLength(const string &st)
    {
        vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
        return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
    }

private:
    int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex,
                               int endIndex)
    {
        if (startIndex > endIndex)
        {
            return 0;
        }

        // every string with one character is a palindrome
        if (startIndex == endIndex)
        {
            return 1;
        }

        if (dp[startIndex][endIndex] == -1)
        {
            int c1 = 0;
            // case 1: elements at the beginning and the end are the same
            if (st[startIndex] == st[endIndex])
            {
                int remainingLength = endIndex - startIndex - 1;
                // if the remaining string is a palindrome too
                if (remainingLength == findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1))
                {
                    c1 = remainingLength + 2;
                }
            }

            // case 2: skip one character either from the beginning or the end
            int c2 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
            int c3 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
            dp[startIndex][endIndex] = max(c1, max(c2, c3));
        }

        return dp[startIndex][endIndex];
    }
};

// Bottom-up Dynamic Programming
class LPS
{

public:
    int findLPSLength(const string &st)
    {
        // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
        vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));

        // every string with one character is a palindrome
        for (int i = 0; i < st.length(); i++)
        {
            dp[i][i] = true;
        }

        int maxLength = 1;
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
                        maxLength = max(maxLength, endIndex - startIndex + 1);
                    }
                }
            }
        }

        return maxLength;
    }
};

// ******** Manacher’s Algorithm **********

/*

The best-known algorithm to find the longest palindromic substring which runs in linear time O(n)
 is Manacher’s Algorithm. However, it is a non-trivial algorithm that doesn’t use DP.

https://en.wikipedia.org/wiki/Longest_palindromic_substring
*/