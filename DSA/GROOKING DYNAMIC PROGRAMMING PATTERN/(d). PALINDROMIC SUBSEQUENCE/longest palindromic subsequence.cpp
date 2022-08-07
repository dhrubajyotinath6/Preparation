/*
Given a sequence, find the length of its Longest Palindromic Subsequence (LPS).
In a palindromic subsequence, elements read the same backward and forward.

A subsequence is a sequence that can be derived from another sequence
by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: "abdbca"
Output: 5
Explanation: LPS is "abdba".


Example 2:

Input: = "cddpd"
Output: 3
Explanation: LPS is "ddd".


Example 3:

Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".

*/

/*
Basic Solution

A basic brute-force solution could be to try all the subsequences of the given sequence.
We can start processing from the beginning and the end of the sequence.

So at any step, we have two options:

1. If the element at the beginning and the end are the same, we increment our count by two
and make a recursive call for the remaining sequence.

2. We will skip the element either from the beginning or the end to make two recursive calls
for the remaining subsequence.

If option one applies then it will give us the length of LPS; otherwise,
the length of LPS will be the maximum number returned by the two recurse calls from the second option.

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

        // every sequence with one element is a palindrome of length 1
        if (startIndex == endIndex)
        {
            return 1;
        }

        // case 1: elements at the beginning and the end are the same
        if (st[startIndex] == st[endIndex])
        {
            return 2 + findLPSLengthRecursive(st, startIndex + 1, endIndex - 1);
        }

        // case 2: skip one element either from the beginning or the end
        int c1 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
        int c2 = findLPSLengthRecursive(st, startIndex, endIndex - 1);
        return max(c1, c2);
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
    int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex, int endIndex)
    {
        if (startIndex > endIndex)
        {
            return 0;
        }

        // every sequence with one element is a palindrome of length 1
        if (startIndex == endIndex)
        {
            return 1;
        }

        if (dp[startIndex][endIndex] == -1)
        {
            // case 1: elements at the beginning and the end are the same
            if (st[startIndex] == st[endIndex])
            {
                dp[startIndex][endIndex] = 2 + findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1);
            }
            else
            {
                // case 2: skip one element either from the beginning or the end
                int c1 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
                int c2 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
                dp[startIndex][endIndex] = max(c1, c2);
            }
        }

        return dp[startIndex][endIndex];
    }
};

// Bottom-up Dynamic Programming
/*
Since we want to try all the subsequences of the given sequence,
we can use a two-dimensional array to store our results.

We can start from the beginning of the sequence and keep adding one element at a time.

At every step, we will try all of its subsequences. So for every startIndex and endIndex in the given string,
we will choose one of the following two options:

If the element at the startIndex matches the element at the endIndex,
the length of LPS would be two plus the length of LPS till startIndex+1 and endIndex-1.

If the element at the startIndex does not match the element at the endIndex,
we will take the maximum LPS created by either skipping element at the startIndex or the endIndex.

So our recursive formula would be:

if st[endIndex] == st[startIndex]
  dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1]
else
  dp[startIndex][endIndex] = Math.max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1])

*/

class LPS
{

public:
    int findLPSLength(const string &st)
    {
        vector<vector<int>> dp(st.length(), vector<int>(st.length(), 0));
        // every sequence with one element is a palindrome of length 1
        for (int i = 0; i < st.length(); i++)
        {
            dp[i][i] = 1;
        }

        for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--)
        {
            for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++)
            {
                // case 1: elements at the beginning and the end are the same
                if (st[startIndex] == st[endIndex])
                {
                    dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1];
                }
                else
                { // case 2: skip one element either from the beginning or the end
                    dp[startIndex][endIndex] =
                        max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1]);
                }
            }
        }
        return dp[0][st.length() - 1];
    }
};
