/*
Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack with a capacity ‘C.’
 The goal is to get the maximum profit out of the knapsack items.
 Each item can only be selected once, as we don’t have multiple quantities of any item.


Let’s take Merry’s example, who wants to carry some fruits in the knapsack to get maximum profit.
 Here are the weights and profits of the fruits:

Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack capacity: 5

Let’s try to put various combinations of fruits in the knapsack,
such that their total weight is not more than 5:

Apple + Orange (total weight 5) => 9 profit
Apple + Banana (total weight 3) => 7 profit
Orange + Banana (total weight 4) => 8 profit
Banana + Melon (total weight 5) => 10 profit

This shows that Banana + Melon is the best combination as it gives us the maximum profit,
and the total weight does not exceed the capacity.

*/

// brute-force

class Knapsack
{
public:
    int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity)
    {
        return this->knapsackRecursive(profits, weights, capacity, 0);
    }

private:
    int knapsackRecursive(const vector<int> &profits, vector<int> &weights, int capacity,
                          int currentIndex)
    {
        // base checks
        if (capacity <= 0 || currentIndex >= profits.size())
        {
            return 0;
        }

        // recursive call after choosing the element at the currentIndex
        // if the weight of the element at currentIndex exceeds the capacity, we shouldn't
        // process this
        int profit1 = 0;
        if (weights[currentIndex] <= capacity)
        {
            profit1 =
                profits[currentIndex] +
                knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
        }

        // recursive call after excluding the element at the currentIndex
        int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

        return max(profit1, profit2);
    }
};

// Top-down Dynamic Programming with Memoization

class Knapsack
{
public:
    virtual int solveKnapsack(const vector<int> &profits, vector<int> &weights,
                              int capacity)
    {
        vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, -1));
        return this->knapsackRecursive(dp, profits, weights, capacity, 0);
    }

private:
    int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits,
                          vector<int> &weights, int capacity, int currentIndex)
    {
        // base checks
        if (capacity <= 0 || currentIndex >= profits.size())
        {
            return 0;
        }

        // if we have already solved a similar problem, return the result from memory
        if (dp[currentIndex][capacity] != -1)
        {
            return dp[currentIndex][capacity];
        }

        // recursive call after choosing the element at the currentIndex
        // if the weight of the element at currentIndex exceeds the capacity, we shouldn't
        // process this
        int profit1 = 0;
        if (weights[currentIndex] <= capacity)
        {
            profit1 = profits[currentIndex] + knapsackRecursive(dp, profits, weights,
                                                                capacity - weights[currentIndex],
                                                                currentIndex + 1);
        }

        // recursive call after excluding the element at the currentIndex
        int profit2 = knapsackRecursive(dp, profits, weights, capacity, currentIndex + 1);

        dp[currentIndex][capacity] = max(profit1, profit2);
        return dp[currentIndex][capacity];
    }
};

// Bottom-up Dynamic Programming

/*
This means that dp[i][c] will represent the maximum knapsack profit for capacity ‘c’ calculated
from the first ‘i’ items.

So, for each item at index ‘i’ (0 <= i < items.length) and capacity ‘c’ (0 <= c <= capacity),
 we have two options:

1. Exclude the item at index ‘i.’ In this case, we will take whatever profit we get from the sub-array
excluding this item => dp[i-1][c]

2. Include the item at index ‘i’ if its weight is not more than the capacity.
In this case, we include its profit plus whatever profit we get from the remaining capacity
and from remaining items => profit[i] + dp[i-1][c-weight[i]]

Finally, our optimal solution will be maximum of the above two values:

  dp[i][c] = max (dp[i-1][c], profit[i] + dp[i-1][c-weight[i]])


*/

class Knapsack
{
public:
    int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity)
    {
        // basic checks
        if (capacity <= 0 || profits.empty() || weights.size() != profits.size())
        {
            return 0;
        }

        int n = profits.size();

        vector<vector<int>> dp(n, vector<int>(capacity + 1));

        // populate the capacity=0 columns, with '0' capacity we have '0' profit
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        // if we have only one weight, we will take it if it is not more than the capacity
        for (int c = 0; c <= capacity; c++)
        {
            if (weights[0] <= c)
            {
                dp[0][c] = profits[0];
            }
        }

        // process all sub-arrays for all the capacities
        for (int i = 1; i < n; i++)
        {
            for (int c = 1; c <= capacity; c++)
            {
                int profit1 = 0, profit2 = 0;
                // include the item, if it is not more than the capacity
                if (weights[i] <= c)
                {
                    profit1 = profits[i] + dp[i - 1][c - weights[i]];
                }
                // exclude the item
                profit2 = dp[i - 1][c];
                // take maximum
                dp[i][c] = max(profit1, profit2);
            }
        }

        // maximum profit will be at the bottom-right corner.
        return dp[n - 1][capacity];
    }
};

// How can we find the selected items?

/*

Can we improve our bottom-up DP solution even further?
Can we find an algorithm that has O(C)O(C) space complexity?

We only need one previous row to find the optimal solution!

*/

// space optimization
class Knapsack
{
public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity)
    {
        // basic checks
        if (capacity <= 0 || profits.empty() || weights.size() != profits.size())
        {
            return 0;
        }

        int n = profits.size();
        // we only need one previous row to find the optimal solution, overall we need '2'
        // rows the above solution is similar to the previous solution, the only difference
        // is that we use `i%2` instead if `i` and `(i-1)%2` instead if `i-1`
        vector<vector<int>> dp(2, vector<int>(capacity + 1));

        // if we have only one weight, we will take it if it is not more than the
        // capacity
        for (int c = 0; c <= capacity; c++)
        {
            if (weights[0] <= c)
            {
                dp[0][c] = dp[1][c] = profits[0];
            }
        }

        // process all sub-arrays for all the capacities
        for (int i = 1; i < n; i++)
        {
            for (int c = 0; c <= capacity; c++)
            {
                int profit1 = 0, profit2 = 0;
                // include the item, if it is not more than the capacity
                if (weights[i] <= c)
                {
                    profit1 = profits[i] + dp[(i - 1) % 2][c - weights[i]];
                }
                // exclude the item
                profit2 = dp[(i - 1) % 2][c];
                // take maximum
                dp[i % 2][c] = max(profit1, profit2);
            }
        }

        return dp[(n - 1) % 2][capacity];
    }
};

// IT STILL CAN BE IMPROVED ???
