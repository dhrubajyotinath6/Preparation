/*
There are n houses built in a line. A thief wants to steal the maximum possible money from these houses. The only restriction the thief has is that he can’t steal from two consecutive houses, as that would alert the security system. How should the thief maximize his stealing?

Problem Statement

Given a number array representing the wealth of n houses, determine the maximum amount of money the thief can steal without alerting the security system.

Example 1:

Input: {2, 5, 1, 3, 6, 2, 4}
Output: 15
Explanation: The thief should steal from houses 5 + 6 + 4
Example 2:

Input: {2, 10, 14, 8, 1}
Output: 18
Explanation: The thief should steal from houses 10 + 8


*/

/*
Basic Solution

Let’s first start with a recursive brute-force solution.

For every house i, we have two options:

(i) Steal from the current house (i), skip one and steal from (i+2).
(ii) Skip the current house (i), and steal from the adjacent house (i+1).

The thief should choose the one with the maximum amount from the above two options

*/

// brute force
class HouseThief
{
public:
    int findMaxSteal(const vector<int> &wealth)
    {
        return findMaxStealRecursive(wealth, 0);
    }

private:
    int findMaxStealRecursive(const vector<int> &wealth, int currentIndex)
    {
        if (currentIndex >= wealth.size())
        {
            return 0;
        }
        // steal from current house and skip one to steal next
        int stealCurrent = wealth[currentIndex] + findMaxStealRecursive(wealth, currentIndex + 2);

        // skip current house to steel from the adjacent house
        int skipCurrent = findMaxStealRecursive(wealth, currentIndex + 1);

        return max(stealCurrent, skipCurrent);
    }
};

// Top-down Dynamic Programming with Memoization
class HouseThief
{
public:
    int findMaxSteal(const vector<int> &wealth)
    {
        vector<int> dp(wealth.size(), 0);
        return findMaxStealRecursive(dp, wealth, 0);
    }

private:
    int findMaxStealRecursive(vector<int> &dp, const vector<int> &wealth, int currentIndex)
    {
        if (currentIndex >= wealth.size())
        {
            return 0;
        }
        if (dp[currentIndex] == 0)
        {
            // steal from current house and skip one to steal next
            int stealCurrent = wealth[currentIndex] + findMaxStealRecursive(dp, wealth, currentIndex + 2);

            // skip current house to steel from the adjacent house
            int skipCurrent = findMaxStealRecursive(dp, wealth, currentIndex + 1);

            dp[currentIndex] = max(stealCurrent, skipCurrent);
        }
        return dp[currentIndex];
    }
};

// Bottom-up Dynamic Programming
class HouseThief
{

public:
    int findMaxSteal(const vector<int> &wealth)
    {
        if (wealth.empty())
        {
            return 0;
        }
        vector<int> dp(wealth.size() + 1); // '+1' to handle the zero house

        dp[0] = 0;         // if there are no houses, the thief can't steal anything
        dp[1] = wealth[0]; // only one house, so the thief have to steal from it

        // please note that dp[] has one extra element to handle zero house
        for (int i = 1; i < wealth.size(); i++)
        {
            dp[i + 1] = max(wealth[i] + dp[i - 1], dp[i]);
        }

        return dp[wealth.size()];
    }
};

// Memory Optimization
class HouseThief
{
public:
    int findMaxSteal(const vector<int> &wealth)
    {
        if (wealth.empty())
        {
            return 0;
        }
        int n1 = 0, n2 = wealth[0], temp;
        for (int i = 1; i < wealth.size(); i++)
        {
            temp = max(n1 + wealth[i], n2);
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
};