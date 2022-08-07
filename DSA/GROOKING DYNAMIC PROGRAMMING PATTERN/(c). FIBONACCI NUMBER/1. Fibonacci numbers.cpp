/*
Write a function to calculate the nth Fibonacci number.

Fibonacci numbers are a series of numbers in which each number is the sum of the two preceding numbers.
First few Fibonacci numbers are: 0, 1, 1, 2, 3, 5, 8, …

Mathematically we can define the Fibonacci numbers as:

    Fib(n) = Fib(n-1) + Fib(n-2), for n > 1

    Given that: Fib(0) = 0, and Fib(1) = 1

*/

// BRUTE FORCE
class Fibonacci
{

public:
    int CalculateFibonacci(int n)
    {
        if (n < 2)
        {
            return n;
        }
        return CalculateFibonacci(n - 1) + CalculateFibonacci(n - 2);
    }
};

// Top-down Dynamic Programming with Memoization
class Fibonacci
{

public:
    int CalculateFibonacci(int n)
    {
        vector<int> dp(n + 1, 0);
        return CalculateFibonacciRecursive(dp, n);
    }

    int CalculateFibonacciRecursive(vector<int> &dp, int n)
    {
        if (n < 2)
        {
            return n;
        }
        if (dp[n] == 0)
        {
            dp[n] = CalculateFibonacciRecursive(dp, n - 1) + CalculateFibonacciRecursive(dp, n - 2);
        }
        return dp[n];
    }
};

// Bottom-up Dynamic Programming
class Fibonacci
{

public:
    int CalculateFibonacci(int n)
    {
        if (n < 2)
        {
            return n;
        }
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Memory Optimization
class Fibonacci
{

public:
    int CalculateFibonacci(int n)
    {
        if (n < 2)
        {
            return n;
        }
        int n1 = 0, n2 = 1, temp;
        for (int i = 2; i <= n; i++)
        {
            temp = n1 + n2;
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
};
