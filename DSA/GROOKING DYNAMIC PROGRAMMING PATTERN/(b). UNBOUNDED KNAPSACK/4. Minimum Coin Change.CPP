/*
Given an infinite supply of ‘n’ coin denominations and a total money amount,
we are asked to find the minimum number of coins needed to make up that amount.

Example 1:

Denominations: {1,2,3}
Total amount: 5
Output: 2
Explanation: We need a minimum of two coins {2,3} to make a total of '5'



Example 2:

Denominations: {1,2,3}
Total amount: 11
Output: 4
Explanation: We need a minimum of four coins {2,3,3,3} to make a total of '11'

Problem Statement

Given a number array to represent different coin denominations and a total amount ‘T’,
we need to find the minimum number of coins needed to make a change for ‘T’.
We can assume an infinite supply of coins, therefore, each coin can be chosen multiple times.

*/

// BRUTE FORCE
class CoinChange
{

public:
    int countChange(const vector<int> &denominations, int total)
    {
        int result = this->countChangeRecursive(denominations, total, 0);
        return (result == numeric_limits<int>::max() ? -1 : result);
    }

private:
    int countChangeRecursive(const vector<int> &denominations, int total,
                             int currentIndex)
    {
        // base check
        if (total == 0)
        {
            return 0;
        }

        if (denominations.empty() || currentIndex >= denominations.size())
        {
            return numeric_limits<int>::max();
        }

        // recursive call after selecting the coin at the currentIndex
        // if the coin at currentIndex exceeds the total, we shouldn't process this
        int count1 = numeric_limits<int>::max();
        if (denominations[currentIndex] <= total)
        {
            int res =
                countChangeRecursive(denominations,
                                     total - denominations[currentIndex], currentIndex);
            if (res != numeric_limits<int>::max())
            {
                count1 = res + 1;
            }
        }

        // recursive call after excluding the coin at the currentIndex
        int count2 = countChangeRecursive(denominations, total, currentIndex + 1);

        return min(count1, count2);
    }
};

// Top-down Dynamic Programming with Memoization

class CoinChange
{

public:
    int countChange(const vector<int> &denominations, int total)
    {
        vector<vector<int>> dp(denominations.size(), vector<int>(total + 1));
        int result = this->countChangeRecursive(dp, denominations, total, 0);
        return (result == numeric_limits<int>::max() ? -1 : result);
    }

private:
    int countChangeRecursive(vector<vector<int>> &dp, const vector<int> &denominations,
                             int total, int currentIndex)
    {
        // base check
        if (total == 0)
        {
            return 0;
        }

        if (denominations.empty() || currentIndex >= denominations.size())
        {
            return numeric_limits<int>::max();
        }

        // check if we have not already processed a similar sub-problem
        if (!dp[currentIndex][total])
        {
            // recursive call after selecting the coin at the currentIndex
            // if the coin at currentIndex exceeds the total, we shouldn't process this
            int count1 = numeric_limits<int>::max();
            if (denominations[currentIndex] <= total)
            {
                int res = countChangeRecursive(dp, denominations,
                                               total - denominations[currentIndex], currentIndex);
                if (res != numeric_limits<int>::max())
                {
                    count1 = res + 1;
                }
            }

            // recursive call after excluding the coin at the currentIndex
            int count2 = countChangeRecursive(dp, denominations, total, currentIndex + 1);
            dp[currentIndex][total] = min(count1, count2);
        }
        return dp[currentIndex][total];
    }
};

// Bottom-up Dynamic Programming
/*
Let’s try to populate our array dp[TotalDenominations][Total+1]
for every possible total with a minimum number of coins needed.

So for every possible total ‘t’ (0<= t <= Total)
and for every possible coin index (0 <= index < denominations.length), we have two options:

1. Exclude the coin: In this case, we will take the minimum coin count from the
previous set => dp[index-1][t]

2. Include the coin if its value is not more than ‘t’:
In this case, we will take the minimum count needed to get the remaining total,
plus include ‘1’ for the current coin => dp[index][t-denominations[index]] + 1
Finally, we will take the minimum of the above two values for our solution:

 dp[index][t] = min(dp[index-1][t], dp[index][t-denominations[index]] + 1)

*/

class CoinChange
{

public:
    int countChange(const vector<int> &denominations, int total)
    {
        int n = denominations.size();
        vector<vector<int>> dp(n, vector<int>(total + 1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= total; j++)
            {
                dp[i][j] = numeric_limits<int>::max();
            }
        }

        // populate the total=0 columns, as we don't need any coin to make zero total
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int t = 1; t <= total; t++)
            {
                if (i > 0)
                {
                    dp[i][t] = dp[i - 1][t]; // exclude the coin
                }
                if (t >= denominations[i])
                {
                    if (dp[i][t - denominations[i]] != numeric_limits<int>::max())
                    {
                        dp[i][t] = min(dp[i][t], dp[i][t - denominations[i]] + 1); // include coin
                    }
                }
            }
        }

        // total combinations will be at the bottom-right corner.
        return (dp[n - 1][total] == numeric_limits<int>::max() ? -1 : dp[n - 1][total]);
    }
};
