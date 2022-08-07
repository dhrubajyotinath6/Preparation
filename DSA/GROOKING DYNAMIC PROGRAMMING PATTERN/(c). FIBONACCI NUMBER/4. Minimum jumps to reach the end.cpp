/*
Given an array of positive numbers, where each element represents the max number of jumps
that can be made forward from that element, write a program to find the minimum number of jumps
needed to reach the end of the array (starting from the first element). If an element is 0,
then we cannot move through that element.

Example 1:

Input = {2,1,1,1,4}
Output = 3
Explanation: Starting from index '0', we can reach the last index through: 0->2->3->4


Example 2:

Input = {1,1,3,6,9,3,0,1,3}
Output = 4
Explanation: Starting from index '0', we can reach the last index through: 0->1->2->3->8


*/

// BRUTE FORCE
class ArrayJump
{
public:
    int countMinJumps(const vector<int> &jumps)
    {
        return this->countMinJumpsRecursive(jumps, 0);
    }

private:
    int countMinJumpsRecursive(const vector<int> &jumps, int currentIndex)
    {
        // if we have reached the last index, we don't need any more jumps
        if (currentIndex == jumps.size() - 1)
        {
            return 0;
        }

        if (jumps[currentIndex] == 0)
        {
            return numeric_limits<int>::max();
        }

        int totalJumps = numeric_limits<int>::max();
        int start = currentIndex + 1;
        int end = currentIndex + jumps[currentIndex];
        while (start < jumps.size() && start <= end)
        {
            // jump one step and recurse for the remaining array
            int minJumps = countMinJumpsRecursive(jumps, start++);
            if (minJumps != numeric_limits<int>::max())
            {
                totalJumps = min(totalJumps, minJumps + 1);
            }
        }
        return totalJumps;
    }
};

// Top-down Dynamic Programming with Memoization

class ArrayJump
{

public:
    int countMinJumps(const vector<int> &jumps)
    {
        vector<int> dp(jumps.size(), 0);
        return this->countMinJumpsRecursive(dp, jumps, 0);
    }

private:
    int countMinJumpsRecursive(vector<int> &dp, const vector<int> &jumps,
                               int currentIndex)
    {
        // if we have reached the last index, we don't need any more jumps
        if (currentIndex == jumps.size() - 1)
        {
            return 0;
        }

        // If an element is 0, then we cannot move through that element
        if (jumps[currentIndex] == 0)
        {
            return numeric_limits<int>::max();
        }

        // if we have already solved this problem, return the result
        if (dp[currentIndex] != 0)
        {
            return dp[currentIndex];
        }

        int totalJumps = numeric_limits<int>::max();

        int start = currentIndex + 1;
        int end = currentIndex + jumps[currentIndex];

        while (start < jumps.size() && start <= end)
        {
            // jump one step and recurse for the remaining array
            int minJumps = countMinJumpsRecursive(dp, jumps, start++);

            if (minJumps != numeric_limits<int>::max())
            {
                totalJumps = min(totalJumps, minJumps + 1);
            }
        }

        dp[currentIndex] = totalJumps;

        return dp[currentIndex];
    }
};

// Bottom-up Dynamic Programming
class ArrayJump
{

public:
    int countMinJumps(const vector<int> &jumps)
    {
        vector<int> dp(jumps.size());

        // initialize with infinity, except the first index which should be zero as we start
        // from there
        for (int i = 1; i < jumps.size(); i++)
        {
            dp[i] = numeric_limits<int>::max();
        }

        for (int start = 0; start < jumps.size() - 1; start++)
        {
            for (int end = start + 1; end <= start + jumps[start] && end < jumps.size(); end++)
            {
                dp[end] = min(dp[end], dp[start] + 1);
            }
        }

        return dp[jumps.size() - 1];
    }
};
