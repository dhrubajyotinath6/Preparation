/*
Given a set of positive numbers, partition the set into two subsets with minimum difference between their subset sums.

Example 1: #
Input: {1, 2, 3, 9}
Output: 3
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} & {9}.


Example 2: #
Input: {1, 2, 7, 1, 5}
Output: 0
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of number is '0'. Following are the two subsets: {1, 2, 5} & {7, 1}.


Example 3: #
Input: {1, 3, 100, 4}
Output: 92
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} & {100}.


*/

// BRUTE FORCE
/*
Let’s assume S1 and S2 are the two desired subsets. A basic brute-force solution could be to try adding each element
either in S1 or S2 in order to find the combination that gives the minimum sum difference between the two sets
*/

class PartitionSet
{
public:
    int canPartition(const vector<int> &num)
    {
        return this->canPartitionRecursive(num, 0, 0, 0);
    }

private:
    int canPartitionRecursive(const vector<int> &num, int currentIndex, int sum1,
                              int sum2)
    {
        // base check
        if (currentIndex == num.size())
        {
            return abs(sum1 - sum2);
        }

        // recursive call after including the number at the currentIndex in the first set
        int diff1 =
            canPartitionRecursive(num, currentIndex + 1, sum1 + num[currentIndex], sum2);

        // recursive call after including the number at the currentIndex in the second set
        int diff2 =
            canPartitionRecursive(num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

        return min(diff1, diff2);
    }
};

// Top-down Dynamic Programming with Memoization
class PartitionSet
{
public:
    int canPartition(const vector<int> &num)
    {
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            sum += num[i];
        }

        vector<vector<int>> dp(num.size(), vector<int>(sum + 1, -1));
        return this->canPartitionRecursive(dp, num, 0, 0, 0);
    }

private:
    int canPartitionRecursive(vector<vector<int>> &dp, const vector<int> &num,
                              int currentIndex, int sum1, int sum2)
    {
        // base check
        if (currentIndex == num.size())
        {
            return abs(sum1 - sum2);
        }

        // check if we have not already processed similar problem
        if (dp[currentIndex][sum1] == -1)
        {
            // recursive call after including the number at the currentIndex in the first set
            int diff1 =
                canPartitionRecursive(dp, num, currentIndex + 1, sum1 + num[currentIndex], sum2);

            // recursive call after including the number at the currentIndex in the second set
            int diff2 =
                canPartitionRecursive(dp, num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

            dp[currentIndex][sum1] = min(diff1, diff2);
        }

        return dp[currentIndex][sum1];
    }
};

// Bottom-up Dynamic Programming
/*
For every possible sum ‘s’ (where 0 <= s <= S/2), we have two options:

1. Exclude the number. In this case, we will see if we can get the sum ‘s’ from the subset
excluding this number => dp[index-1][s]

2. Include the number if its value is not more than ‘s’. In this case, we will see
if we can find a subset to get the remaining sum => dp[index-1][s-num[index]]

If either of the two above scenarios is true, we can find a subset with a sum equal to ‘s’.
We should dig into this before we can learn how to find the closest subset.
*/

class PartitionSet
{
public:
    virtual int canPartition(const vector<int> &num)
    {
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            sum += num[i];
        }

        int n = num.size();
        vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));

        // populate the sum=0 columns, as we can always form '0' sum with an empty set
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        // with only one number, we can form a subset only when sum is equal to that number
        for (int s = 0; s <= sum / 2; s++)
        {
            dp[0][s] = (num[0] == s ? true : false);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++)
        {
            for (int s = 1; s <= sum / 2; s++)
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

        int sum1 = 0;
        // Find the largest index in the last row which is true
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[n - 1][i] == true)
            {
                sum1 = i;
                break;
            }
        }

        int sum2 = sum - sum1;
        return abs(sum2 - sum1);
    }
};
