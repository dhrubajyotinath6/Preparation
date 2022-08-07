/*
Given an infinite supply of ‘n’ coin denominations and a total money amount,
we are asked to find the total number of distinct ways to make up that amount.

Example:

Denominations: {1,2,3}
Total amount: 5
Output: 5
Explanation: There are five ways to make the change for '5', here are those ways:
  1. {1,1,1,1,1}
  2. {1,1,1,2}
  3. {1,2,2}
  4. {1,1,3}
  5. {2,3}

Problem Statement

Given a number array to represent different coin denominations and a total amount ‘T’,
we need to find all the different ways to make a change for ‘T’ with the given coin denominations.
We can assume an infinite supply of coins, therefore, each coin can be chosen multiple times.


*/

// BRUTE FORCE
class CoinChange
{
public:
    int countChange(const vector<int> &denominations, int total)
    {
        return this->countChangeRecursive(denominations, total, 0);
    }

private:
    int countChangeRecursive(const vector<int> &denominations, int total,
                             int currentIndex)
    {
        // base checks
        if (total == 0)
        {
            return 1;
        }
        if (denominations.empty() || currentIndex >= denominations.size())
        {
            return 0;
        }
        // recursive call after selecting the coin at the currentIndex
        // if the coin at currentIndex exceeds the total, we shouldn't process this
        int sum1 = 0;
        if (denominations[currentIndex] <= total)
        {
            sum1 = countChangeRecursive(denominations,
                                        total - denominations[currentIndex], currentIndex);
        }
        // recursive call after excluding the coin at the currentIndex
        int sum2 = countChangeRecursive(denominations, total, currentIndex + 1);
        return sum1 + sum2;
    }
};

// Top-down Dynamic Programming with Memoization
class CoinChange
{

public:
    int countChange(const vector<int> &denominations, int total)
    {
        vector<vector<int>> dp(denominations.size(), vector<int>(total + 1));
        return this->countChangeRecursive(dp, denominations, total, 0);
    }

private:
    int countChangeRecursive(vector<vector<int>> &dp, const vector<int> &denominations,
                             int total, int currentIndex)
    {
        // base checks
        if (total == 0)
        {
            return 1;
        }

        if (denominations.empty() || currentIndex >= denominations.size())
        {
            return 0;
        }

        // if we have already processed a similar sub-problem, return the result from memory
        if (dp[currentIndex][total])
        {
            return dp[currentIndex][total];
        }

        // recursive call after selecting the coin at the currentIndex
        // if the number at currentIndex exceeds the total, we shouldn't process this
        int sum1 = 0;
        if (denominations[currentIndex] <= total)
        {
            sum1 = countChangeRecursive(dp, denominations, total - denominations[currentIndex],
                                        currentIndex);
        }

        // recursive call after excluding the number at the currentIndex
        int sum2 = countChangeRecursive(dp, denominations, total, currentIndex + 1);

        dp[currentIndex][total] = sum1 + sum2;
        return dp[currentIndex][total];
    }
};

// Bottom-up Dynamic Programming
/*
We will try to find if we can make all possible sums, with every combination of coins,
to populate the array dp[TotalDenominations][Total+1].

So for every possible total ‘t’ (0<= t <= Total)
and for every possible coin index (0 <= index < denominations.length), we have two options:

1. Exclude the coin. Count all the coin combinations without the given coin up to the
total ‘t’ => dp[index-1][t]

2. Include the coin if its value is not more than ‘t’.
In this case, we will count all the coin combinations to get the
remaining total: dp[index][t-denominations[index]]
Finally, to find the total combinations, we will add both the above two values:

  dp[index][t] = dp[index-1][t] + dp[index][t-denominations[index]]


*/

class CoinChange
{

public:
    int countChange(const vector<int> &denominations, int total)
    {
        int n = denominations.size();
        vector<vector<int>> dp(n, vector<int>(total + 1));

        // populate the total=0 columns, as we will always have an empty set for zero total
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        // process all sub-arrays for all capacities

        for (int i = 0; i < n; i++)
        {
            for (int t = 1; t <= total; t++)
            {
                if (i > 0)
                {
                    dp[i][t] = dp[i - 1][t];
                }
                if (t >= denominations[i])
                {
                    dp[i][t] += dp[i][t - denominations[i]];
                }
            }
        }

        // total combinations will be at the bottom-right corner.
        return dp[n - 1][total];
    }
};
