/*
Given a rod of length ‘n’, we are asked to cut the rod and sell the pieces in a way
that will maximize the profit. We are also given the price of every piece of length ‘i’
where ‘1 <= i <= n’.

Example:

Lengths: [1, 2, 3, 4, 5]
Prices: [2, 6, 7, 10, 13]
Rod Length: 5

Let’s try different combinations of cutting the rod:

Five pieces of length 1 => 10 price
Two pieces of length 2 and one piece of length 1 => 14 price
One piece of length 3 and two pieces of length 1 => 11 price
One piece of length 3 and one piece of length 2 => 13 price
One piece of length 4 and one piece of length 1 => 12 price
One piece of length 5 => 13 price

This shows that we get the maximum price (14) by cutting the rod into two pieces of length ‘2’
 and one piece of length ‘1’.


*/

/*
Let’s try to populate our dp[][] array in a bottom-up fashion.
Essentially, what we want to achieve is:
“Find the maximum sales price for every rod length and for every possible sales price”.

So for every possible rod length ‘len’ (0<= len <= n), we have two options:

1. Exclude the piece. In this case, we will take whatever price we get from the rod length
excluding this piece
=> dp[index-1][len]

2. Include the piece if its length is not more than ‘len’.
In this case, we include its price plus whatever price we get from the remaining rod length
=> prices[index] + dp[index][len-lengths[index]]

Finally, we have to take the maximum of the above two values:

dp[index][len] =
     max (dp[index-1][len], prices[index] + dp[index][len-lengths[index]])

*/

class RodCutting
{

public:
    int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int n)
    {
        // base checks
        if (n <= 0 || prices.empty() || prices.size() != lengths.size())
        {
            return 0;
        }

        int lengthCount = lengths.size();
        vector<vector<int>> dp(lengthCount, vector<int>(n + 1));

        // process all rod lengths for all prices
        for (int i = 0; i < lengthCount; i++)
        {
            for (int len = 1; len <= n; len++)
            {
                int p1 = 0, p2 = 0;
                if (lengths[i] <= len)
                {
                    p1 = prices[i] + dp[i][len - lengths[i]];
                }
                if (i > 0)
                {
                    p2 = dp[i - 1][len];
                }
                dp[i][len] = max(p1, p2);
            }
        }

        // maximum price will be at the bottom-right corner.
        return dp[lengthCount - 1][n];
    }
};

// Find the selected items????
