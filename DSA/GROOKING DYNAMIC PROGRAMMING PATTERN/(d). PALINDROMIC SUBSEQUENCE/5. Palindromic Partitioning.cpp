/*
Given a string, we want to cut it into pieces such that each piece is a palindrome.
Write a function to return the minimum number of cuts needed.

Example 1:

Input: "abdbca"
Output: 3
Explanation: Palindrome pieces are "a", "bdb", "c", "a".


Example 2:

Input: = "cddpd"
Output: 2
Explanation: Palindrome pieces are "c", "d", "dpd".


Example 3:

Input: = "pqr"
Output: 2
Explanation: Palindrome pieces are "p", "q", "r".


Example 4:

Input: = "pp"
Output: 0
Explanation: We do not need to cut, as "pp" is a palindrome.

*/

/*
This problem follows the Longest Palindromic Subsequence pattern and shares a similar approach as
that of the Longest Palindromic Substring.

The brute-force solution will be to try all the substring combinations of the given string.
We can start processing from the beginning of the string and keep adding one character at a time.
 At any step, if we get a palindrome, we take it as one piece and recursively process
 the remaining length of the string to find the minimum cuts needed.


*/

class MPP
{

public:
    int findMPPCuts(const string &st)
    {
        return this->findMPPCutsRecursive(st, 0, st.length() - 1);
    }

private:
    int findMPPCutsRecursive(const string &st, int startIndex, int endIndex)
    {
        // we don't need to cut the string if it is a palindrome
        if (startIndex >= endIndex || isPalindrome(st, startIndex, endIndex))
        {
            return 0;
        }

        // at max, we need to cut the string into its 'length-1' pieces
        int minimumCuts = endIndex - startIndex;
        for (int i = startIndex; i <= endIndex; i++)
        {
            if (isPalindrome(st, startIndex, i))
            {
                // we can cut here as we have a palindrome from 'startIndex' to 'i'
                minimumCuts = min(minimumCuts, 1 + findMPPCutsRecursive(st, i + 1, endIndex));
            }
        }
        return minimumCuts;
    }

    bool isPalindrome(const string &st, int x, int y)
    {
        while (x < y)
        {
            if (st[x++] != st[y--])
            {
                return false;
            }
        }
        return true;
    }
};

// Top-down Dynamic Programming with Memoization
class MPP
{

public:
    int findMPPCuts(const string &st)
    {
        vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
        vector<vector<int>> dpIsPalindrome(st.length(), vector<int>(st.length(), -1));
        return this->findMPPCutsRecursive(dp, dpIsPalindrome, st, 0, st.length() - 1);
    }

private:
    int findMPPCutsRecursive(vector<vector<int>> &dp, vector<vector<int>> &dpIsPalindrome,
                             const string &st, int startIndex, int endIndex)
    {

        if (startIndex >= endIndex ||
            isPalindrome(dpIsPalindrome, st, startIndex, endIndex))
        {
            return 0;
        }

        if (dp[startIndex][endIndex] == -1)
        {
            // at max, we need to cut the string into its 'length-1' pieces
            int minimumCuts = endIndex - startIndex;
            for (int i = startIndex; i <= endIndex; i++)
            {
                if (isPalindrome(dpIsPalindrome, st, startIndex, i))
                {
                    // we can cut here as we have a palindrome from 'startIndex' to 'i'
                    minimumCuts =
                        min(minimumCuts,
                            1 + findMPPCutsRecursive(dp, dpIsPalindrome, st, i + 1, endIndex));
                }
            }
            dp[startIndex][endIndex] = minimumCuts;
        }
        return dp[startIndex][endIndex];
    }

    bool isPalindrome(vector<vector<int>> &dpIsPalindrome, const string &st, int x,
                      int y)
    {
        if (dpIsPalindrome[x][y] == -1)
        {
            dpIsPalindrome[x][y] = 1;
            int i = x, j = y;
            while (i < j)
            {
                if (st[i++] != st[j--])
                {
                    dpIsPalindrome[x][y] = 0;
                    break;
                }
                // use memoization to find if the remaining string is a palindrome
                if (i < j && dpIsPalindrome[i][j] == 1)
                {
                    dpIsPalindrome[x][y] = dpIsPalindrome[i][j];
                    break;
                }
            }
        }

        return dpIsPalindrome[x][y] == 1;
    }
};

// Bottom-up Dynamic Programming
class MPP
{

public:
    int findMPPCuts(const string &st)
    {
        // isPalindrome[i][j] will be 'true' if the string from index 'i' to index 'j' is
        // a palindrome
        vector<vector<bool>> isPalindrome(st.length(), vector<bool>(st.length(), false));

        // every string with one character is a palindrome
        for (int i = 0; i < st.length(); i++)
        {
            isPalindrome[i][i] = true;
        }

        // populate isPalindrome table
        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--)
        {
            for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++)
            {
                if (st[startIndex] == st[endIndex])
                {
                    // if it's a two character string or the remaining string is a palindrome too
                    if (endIndex - startIndex == 1 || isPalindrome[startIndex + 1][endIndex - 1])
                    {
                        isPalindrome[startIndex][endIndex] = true;
                    }
                }
            }
        }

        // now lets populate the second table, every index in 'cuts' stores the minimum cuts
        // needed for the substring from that index till the end
        vector<int> cuts(st.length(), 0);
        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--)
        {
            int minCuts = st.length(); // maximum cuts
            for (int endIndex = st.length() - 1; endIndex >= startIndex; endIndex--)
            {
                if (isPalindrome[startIndex][endIndex])
                {
                    // we can cut here as we got a palindrome
                    // also we dont need any cut if the whole substring is a palindrome
                    minCuts =
                        (endIndex == st.length() - 1) ? 0 : min(minCuts, 1 + cuts[endIndex + 1]);
                }
            }
            cuts[startIndex] = minCuts;
        }

        return cuts[0];
    }
};
