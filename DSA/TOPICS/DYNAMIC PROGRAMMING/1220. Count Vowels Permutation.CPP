Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4




/*
start   =>  a / e / i / o / u   # start denotes 1st character of string which can be any vowel
a       =>  e
e       =>  a / i
i       =>  a / e / o / u
o       =>  i / u
u       =>  a


https://leetcode.com/problems/count-vowels-permutation/discuss/1315039/Optimization-from-Brute-Force-to-DP-to-O(1)-Time-Solutions-or-Explained

https://leetcode.com/problems/count-vowels-permutation/discuss/1315113/C%2B%2BJavaPython-Top-down-DP-Bottom-up-DP-Picture-explain-Clean-and-Concise


https://leetcode.com/problems/count-vowels-permutation/discuss/398222/Detailed-Explanation-using-Graphs-With-Pictures-O(n)
*/
class Solution{
public:
    int countVowelPermutation(int n);
};

int Solution :: countVowelPermutation(int n)
{
    vector<vector<long>> dp(n+1, vector<long>(5, 0));
    
    int MOD = 1e9 + 7;
    
    /* dp[i][j] denotes the number of valid strings of length i */
    
    for(int i = 0; i < 5; i++)
        dp[1][i] = 1;
    
    for(int i = 1; i < n; i++)
    {
        dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) %MOD;
        
        dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD;
        
        dp[i+1][2] = (dp[i][1] + dp[i][3]) % MOD;
        
        dp[i+1][3] = dp[i][2];
        
        dp[i+1][4] = (dp[i][2] + dp[i][3]) % MOD;
    }
    
    int res = 0;
    for(int i = 0; i < 5; i++)
        res = (res + dp[n][i]) % MOD;
    
    return res;
}