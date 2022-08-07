/*
Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack
that has a capacity ‘C’. The goal is to get the maximum profit from the items in the knapsack.
The only difference between the 0/1 Knapsack problem and this problem is that we are allowed
to use an unlimited quantity of an item.

Let’s take the example of Merry, who wants to carry some fruits in the knapsack to get maximum profit.
Here are the weights and profits of the fruits:

Items: { Apple, Orange, Melon }
Weights: { 1, 2, 3 }
Profits: { 15, 20, 50 }
Knapsack capacity: 5

Let’s try to put different combinations of fruits in the knapsack,
such that their total weight is not more than 5.

5 Apples (total weight 5) => 75 profit
1 Apple + 2 Oranges (total weight 5) => 55 profit
2 Apples + 1 Melon (total weight 5) => 80 profit
1 Orange + 1 Melon (total weight 5) => 70 profit

This shows that 2 apples + 1 melon is the best combination, as it gives us the maximum profit
and the total weight does not exceed the capacity.

*/

// brute-force
class Knapsack
{

public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                      int capacity)
    {
        return this->knapsackRecursive(profits, weights, capacity, 0);
    }

private:
    int knapsackRecursive(const vector<int> &profits, const vector<int> &weights,
                          int capacity, int currentIndex)
    {
        // base checks
        if (capacity <= 0 || profits.empty() || weights.size() != profits.size() ||
            currentIndex >= profits.size())
        {
            return 0;
        }

        // recursive call after choosing the items at the currentIndex, note that we
        // recursive call on all items as we did not increment currentIndex
        int profit1 = 0;
        if (weights[currentIndex] <= capacity)
        {
            profit1 = profits[currentIndex] + knapsackRecursive(profits, weights,
                                                                capacity - weights[currentIndex], currentIndex);
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
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights,
                      int capacity)
    {
        vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1));
        return this->knapsackRecursive(dp, profits, weights, capacity, 0);
    }

private:
    int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits,
                          const vector<int> &weights, int capacity, int currentIndex)
    {

        // base checks
        if (capacity <= 0 || profits.empty() || weights.size() != profits.size() ||
            currentIndex >= profits.size())
        {
            return 0;
        }

        // check if we have not already processed a similar sub-problem
        if (!dp[currentIndex][capacity])
        {
            // recursive call after choosing the items at the currentIndex, note that we
            // recursive call on all items as we did not increment currentIndex
            int profit1 = 0;
            if (weights[currentIndex] <= capacity)
            {
                profit1 =
                    profits[currentIndex] + knapsackRecursive(dp, profits, weights,
                                                              capacity - weights[currentIndex], currentIndex);
            }

            // recursive call after excluding the element at the currentIndex
            int profit2 = knapsackRecursive(dp, profits, weights, capacity, currentIndex + 1);

            dp[currentIndex][capacity] = max(profit1, profit2);
        }

        return dp[currentIndex][capacity];
    }
};

// Bottom-up Dynamic Programming

/*
Let’s try to populate our dp[][] array from the above solution, working in a bottom-up fashion.
 Essentially, what we want to achieve is: “Find the maximum profit for every sub-array
 and for every possible capacity”.

So for every possible capacity ‘c’ (0 <= c <= capacity), we have two options:

1. Exclude the item. In this case, we will take whatever profit we get from the sub-array excluding this item: dp[index-1][c]
2. Include the item if its weight is not more than the ‘c’. In this case, we include its profit plus whatever profit we get from the remaining capacity: profit[index] + dp[index][c-weight[index]]

Finally, we have to take the maximum of the above two values:

 dp[index][c] = max (dp[index-1][c], profit[index] + dp[index][c-weight[index]])

*/

class Knapsack
{

public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity)
    {
        // base checks
        if (capacity <= 0 || profits.empty() || weights.size() != profits.size())
        {
            return 0;
        }

        int n = profits.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1));

        // populate the capacity=0 columns
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        // process all sub-arrays for all capacities
        for (int i = 0; i < n; i++)
        {
            for (int c = 1; c <= capacity; c++)
            {
                int profit1 = 0, profit2 = 0;
                if (weights[i] <= c)
                {
                    profit1 = profits[i] + dp[i][c - weights[i]];
                }
                if (i > 0)
                {
                    profit2 = dp[i - 1][c];
                }
                dp[i][c] = profit1 > profit2 ? profit1 : profit2;
            }
        }

        // maximum profit will be in the bottom-right corner.
        return dp[n - 1][capacity];
    }
};

// FIND THE SELECTED ITEMS??