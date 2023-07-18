Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.


//https://leetcode.com/problems/count-ways-to-build-good-strings/solution/
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int mod = 1000000007;
        
        
        for(int i = 1; i <= high; i++){
            if(i >= zero){
                dp[i] += dp[i-zero];
            }
            if(i >= one){
                dp[i] += dp[i-one];
            }
            
            dp[i] %= mod;
        }
        
        
        
        int ans = 0;
        for(int i = low; i <= high; i++){
            ans += dp[i];
            ans %= mod;
        }
        
        return ans;
    }
};