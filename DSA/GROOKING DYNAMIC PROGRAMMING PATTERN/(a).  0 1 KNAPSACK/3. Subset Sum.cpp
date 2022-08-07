/*
Given a set of positive numbers, determine if a subset exists whose sum is equal to a given number ‘S’.

Example 1: #
Input: {1, 2, 3, 7}, S=6
Output: True
The given set has a subset whose sum is '6': {1, 2, 3}


Example 2: #
Input: {1, 2, 7, 1, 5}, S=10
Output: True
The given set has a subset whose sum is '10': {1, 2, 7}


Example 3: #
Input: {1, 3, 4, 8}, S=6
Output: False
The given set does not have any subset whose sum is equal to '6'.

*/

// Bottom-up Dynamic Programming

/*
We’ll try to find if we can make all possible sums with every subset to populate
the array dp[TotalNumbers][S+1].

For every possible sum ‘s’ (where 0 <= s <= S), we have two options:

    1.Exclude the number. In this case, we will see if we can get the sum ‘s’ from the subset
excluding this number => dp[index-1][s]

    2.Include the number if its value is not more than ‘s’. In this case, we will see if we can find a subset
to get the remaining sum => dp[index-1][s-num[index]]

If either of the above two scenarios returns true, we can find a subset with a sum equal to ‘s’.
*/

class SubsetSum
{
public:
    virtual bool canPartition(const vector<int> &num, int sum)
    {
        int n = num.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1));

        // populate the sum=0 columns, as we can always form '0' sum with an empty set
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        // with only one number, we can form a subset only when the required sum is equal to
        // its value
        for (int s = 1; s <= sum; s++)
        {
            dp[0][s] = (num[0] == s ? true : false);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++)
        {
            for (int s = 1; s <= sum; s++)
            {
                // if we can get the sum 's' without the number at index 'i'
                if (dp[i - 1][s])
                {
                    dp[i][s] = dp[i - 1][s];
                }
                else if (s >= num[i])
                {
                    // else include the number and see if we can find a subset to get the
                    // remaining sum
                    dp[i][s] = dp[i - 1][s - num[i]];
                }
            }
        }

        // the bottom-right corner will have our answer.
        return dp[num.size() - 1][sum];
    }
};

/*
Challenge

Can we improve our bottom-up DP solution even further?
Can we find an algorithm that has O(S)O(S) space complexity?

*/

class SubsetSum
{
public:
    bool canPartition(const vector<int> &num, int sum)
    {
        int n = num.size();
        vector<bool> dp(sum + 1);

        // handle sum=0, as we can always have '0' sum with an empty set
        dp[0] = true;

        // with only one number, we can have a subset only when the required sum is equal to
        // its value
        for (int s = 1; s <= sum; s++)
        {
            dp[s] = (num[0] == s ? true : false);
        }

        // process all subsets for all sums
        for (int i = 1; i < n; i++)
        {
            for (int s = sum; s >= 0; s--)
            {
                // if dp[s]==true, this means we can get the sum 's' without num[i], hence we
                // can move on to the next number else we can include num[i] and see if we can
                // find a subset to get the remaining sum
                if (!dp[s] && s >= num[i])
                {
                    dp[s] = dp[s - num[i]];
                }
            }
        }

        return dp[sum];
    }
};
