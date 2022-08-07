/*
We are given a ribbon of length ‘n’ and a set of possible ribbon lengths.
We need to cut the ribbon into the maximum number of pieces
that comply with the above-mentioned possible lengths. Write a method that will return the count of pieces.

Example 1:

n: 5
Ribbon Lengths: {2,3,5}
Output: 2
Explanation: Ribbon pieces will be {2,3}.
Example 2:

n: 7
Ribbon Lengths: {2,3}
Output: 3
Explanation: Ribbon pieces will be {2,2,3}.
Example 3:

n: 13
Ribbon Lengths: {3,5,7}
Output: 3
Explanation: Ribbon pieces will be {3,3,7}.

Problem Statement

Given a number array to represent possible ribbon lengths and a total ribbon length ‘n,’
 we need to find the maximum number of pieces that the ribbon can be cut into.

This problem follows the Unbounded Knapsack pattern and is quite similar to Minimum Coin Change (MCC).
 The only difference is that in MCC, we were asked to find the minimum number of coin changes,
 whereas, in this problem, we need to find the maximum number of pieces
*/

// BRUTE FORCE
class CutRibbon
{

public:
    int countRibbonPieces(const vector<int> &ribbonLengths, int total)
    {
        int maxPieces = this->countRibbonPiecesRecursive(ribbonLengths, total, 0);
        return maxPieces == numeric_limits<int>::min() ? -1 : maxPieces;
    }

private:
    int countRibbonPiecesRecursive(const vector<int> &ribbonLengths, int total,
                                   int currentIndex)
    {
        // base check
        if (total == 0)
        {
            return 0;
        }

        if (ribbonLengths.empty() || currentIndex >= ribbonLengths.size())
        {
            return numeric_limits<int>::min();
        }

        // recursive call after selecting the ribbon length at the currentIndex, if the
        // ribbon length at the currentIndex exceeds the total, we shouldn't process this
        int c1 = numeric_limits<int>::min();
        if (ribbonLengths[currentIndex] <= total)
        {
            int result = countRibbonPiecesRecursive(ribbonLengths,
                                                    total - ribbonLengths[currentIndex], currentIndex);
            if (result != numeric_limits<int>::min())
            {
                c1 = result + 1;
            }
        }

        // recursive call after excluding the ribbon length at the currentIndex
        int c2 = countRibbonPiecesRecursive(ribbonLengths, total, currentIndex + 1);
        return max(c1, c2);
    }
};

// Bottom-up Dynamic Programming

/*
Let’s try to populate our array dp[ribbonLength][total+1] for every possible ribbon length
 with a maximum number of pieces.

So for every possible length ‘len’ (0 <= len <= total) and
for every possible ribbon length index (0 <= index < ribbonLengths.length), we have two options:

1. Exclude the ribbon length: In this case, we will take the maximum piece count
from the previous set => dp[index-1][len]
2. Include the ribbon length if its value is not more than ‘len’: In this case,
we will take the maximum pieces needed to get the remaining total,
plus include ‘1’ for the current ribbon length => 1 + dp[index][len-ribbonLengths[index]]

Finally, we will take the maximum of the above two values for our solution:

  dp[index][len] = max(dp[index-1][len], 1 + dp[index][len-ribbonLengths[index]])
*/

class CutRibbon
{

public:
    int countRibbonPieces(const vector<int> &ribbonLengths, int total)
    {
        int n = ribbonLengths.size();
        vector<vector<int>> dp(n, vector<int>(total + 1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= total; j++)
            {
                dp[i][j] = numeric_limits<int>::min();
            }
        }

        // populate the total=0 columns, as we don't need any ribbon to make zero total
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int t = 1; t <= total; t++)
            {
                if (i > 0) // exclude the ribbon
                {
                    dp[i][t] = dp[i - 1][t];
                }
                // include the ribbon and check if the remaining length can be cut into
                // available lengths
                if (t >= ribbonLengths[i] && dp[i][t - ribbonLengths[i]] != numeric_limits<int>::min())
                {
                    dp[i][t] = max(dp[i][t], dp[i][t - ribbonLengths[i]] + 1);
                }
            }
        }

        // total combinations will be at the bottom-right corner, return '-1' if cutting is
        // not possible
        return (dp[n - 1][total] == numeric_limits<int>::min() ? -1 : dp[n - 1][total]);
    }
};
