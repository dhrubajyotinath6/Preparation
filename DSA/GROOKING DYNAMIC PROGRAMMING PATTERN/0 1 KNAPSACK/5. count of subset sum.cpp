/*
Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.

Example 1: #
Input: {1, 1, 2, 3}, S=4
Output: 3
The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
Note that we have two similar sets {1, 3}, because we have two '1' in our input.


Example 2: #
Input: {1, 2, 7, 1, 5}, S=9
Output: 3
The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}


*/

// brute-force
class SubsetSum
{
public:
    virtual int countSubsets(const vector<int> &num, int sum)
    {
        return this->countSubsetsRecursive(num, sum, 0);
    }

private:
    int countSubsetsRecursive(const vector<int> &num, int sum, int currentIndex)
    {
        // base checks
        if (sum == 0)
        {
            return 1;
        }

        if (num.empty() || currentIndex >= num.size())
        {
            return 0;
        }

        // recursive call after selecting the number at the currentIndex
        // if the number at currentIndex exceeds the sum, we shouldn't process this
        int sum1 = 0;
        if (num[currentIndex] <= sum)
        {
            sum1 = countSubsetsRecursive(num, sum - num[currentIndex], currentIndex + 1);
        }

        // recursive call after excluding the number at the currentIndex
        int sum2 = countSubsetsRecursive(num, sum, currentIndex + 1);

        return sum1 + sum2;
    }
};

// Top-down Dynamic Programming with Memoization
class SubsetSum
{
public:
    virtual int countSubsets(const vector<int> &num, int sum)
    {
        vector<vector<int>> dp(num.size(), vector<int>(sum + 1, -1));
        return this->countSubsetsRecursive(dp, num, sum, 0);
    }

private:
    int countSubsetsRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum,
                              int currentIndex)
    {
        // base checks
        if (sum == 0)
        {
            return 1;
        }

        if (num.empty() || currentIndex >= num.size())
        {
            return 0;
        }

        // check if we have not already processed a similar problem
        if (dp[currentIndex][sum] == -1)
        {
            // recursive call after choosing the number at the currentIndex
            // if the number at currentIndex exceeds the sum, we shouldn't process this
            int sum1 = 0;
            if (num[currentIndex] <= sum)
            {
                sum1 = countSubsetsRecursive(dp, num, sum - num[currentIndex], currentIndex + 1);
            }

            // recursive call after excluding the number at the currentIndex
            int sum2 = countSubsetsRecursive(dp, num, sum, currentIndex + 1);

            dp[currentIndex][sum] = sum1 + sum2;
        }

        return dp[currentIndex][sum];
    }
};

// Bottom - up Dynamic Programming

/*
We will try to find if we can make all possible sums with every subset
to populate the array db[TotalNumbers][S+1].

So, at every step we have two options:

1. Exclude the number. Count all the subsets without the given number up to the given sum => dp[index-1][sum]
2. Include the number if its value is not more than the ‘sum’.
In this case, we will count all the subsets to get the remaining sum => dp[index-1][sum-num[index]]

To find the total sets, we will add both of the above two values:

  dp[index][sum] = dp[index-1][sum] + dp[index-1][sum-num[index]])


*/

class SubsetSum
{
public:
    virtual int countSubsets(const vector<int> &num, int sum)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // populate the sum=0 columns, as we will always have an empty set for zero sum
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        // with only one number, we can form a subset only when the required sum is
        // equal to its value
        for (int s = 1; s <= sum; s++)
        {
            dp[0][s] = (num[0] == s ? 1 : 0);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++)
        {
            for (int s = 1; s <= sum; s++)
            {
                // exclude the number
                dp[i][s] = dp[i - 1][s];
                // include the number, if it does not exceed the sum
                if (s >= num[i])
                {
                    dp[i][s] += dp[i - 1][s - num[i]];
                }
            }
        }

        // the bottom-right corner will have our answer.
        return dp[num.size() - 1][sum];
    }
};

// Challenge

/*

Can we improve our bottom-up DP solution even further?
Can we find an algorithm that has O(S)O(S) space complexity?

Similar to the space optimized solution for 0/1 Knapsack!

*/

class SubsetSum
{
public:
    static int countSubsets(const vector<int> &num, int sum)
    {
        int n = num.size();
        vector<int> dp(sum + 1);
        dp[0] = 1;

        // with only one number, we can form a subset only when the required sum is
        // equal to its value
        for (int s = 1; s <= sum; s++)
        {
            dp[s] = (num[0] == s ? 1 : 0);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++)
        {
            for (int s = sum; s >= 0; s--)
            {
                if (s >= num[i])
                {
                    dp[s] += dp[s - num[i]];
                }
            }
        }

        return dp[sum];
    }
};