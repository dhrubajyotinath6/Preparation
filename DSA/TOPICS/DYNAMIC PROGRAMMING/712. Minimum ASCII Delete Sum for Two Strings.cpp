Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.



Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.




//basic recursion
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        
        // Call helper function for complete strings
        return computeCost(s1, s2, s1.length()-1, s2.length()-1);
    }

    // Return minimum cost to make s1[0...i] and s2[0...j] equal
    private int computeCost(String s1, String s2, int i, int j) {

        // If s1 is empty, then we need to delete all characters of s2
        if (i < 0) {
            int deleteCost = 0;
            for (int pointer = 0; pointer <= j; pointer++) {
                deleteCost += s2.charAt(pointer);
            }
            return deleteCost;
        }

        // If s2 is empty, then we need to delete all characters of s1
        if (j < 0) {
            int deleteCost = 0;
            for (int pointer = 0; pointer <= i; pointer++) {
                deleteCost += s1.charAt(pointer);
            }
            return deleteCost;
        }

        // Check s1[i] and s2[j]
        if (s1.charAt(i) == s2.charAt(j)) {
            return computeCost(s1, s2, i-1, j-1);
        } else {
            return Math.min(
                s1.charAt(i) + computeCost(s1, s2, i-1, j),
                Math.min(
                    s2.charAt(j) + computeCost(s1, s2, i, j-1),
                    s1.charAt(i) + s2.charAt(j) + computeCost(s1, s2, i-1, j-1)
                )
            );
        }
    }
}


//with memo && only 2 recursion calls
class Solution {

    // Hash Map to store the result of each sub-problem.
    Map<Pair<Integer, Integer>, Integer> savedResult = new HashMap<>();
        
    public int minimumDeleteSum(String s1, String s2) {
        
        // Return minimum cost to make s1[0...i] and s2[0...j] equal
        return computeCost(s1, s2, s1.length()-1, s2.length()-1);
    }

    private int computeCost(String s1, String s2, int i, int j) {

        // If both strings are empty, then no deletion is required
        if (i < 0 && j < 0) {
            return 0;
        }

        // If already computed, then return the result from the hash map
        Pair<Integer, Integer> key = new Pair<>(i, j);
        if (savedResult.containsKey(key)) {
            return savedResult.get(key);
        }
        
        // If any one string is empty, delete all characters of the other string
        if (i < 0) {
            savedResult.put(key, s2.charAt(j) + computeCost(s1, s2, i, j-1));
            return savedResult.get(key);
        }
        if (j < 0) {
            savedResult.put(key, s1.charAt(i) + computeCost(s1, s2, i-1, j));
            return savedResult.get(key);
        }
        
        // Call sub-problem depending on s1[i] and s2[j]
        // Save the computed result.
        if (s1.charAt(i) == s2.charAt(j)) {
            savedResult.put(key, computeCost(s1, s2, i-1, j-1));
        } else {
            savedResult.put(key, Math.min(
                s1.charAt(i) + computeCost(s1, s2, i-1, j),
                s2.charAt(j) + computeCost(s1, s2, i, j-1)
            ));
        }
        return savedResult.get(key);
    }
}



//TABULATION
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m = s1.length(),  n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        
        for(int j = 1; j <= n; j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        
        
        for(int i = 1; i <= m ; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
                }
            }
        }
        
      return dp[m][n];  
    }
};


//we can space optimized it though as we are only dependent on prev row -->https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/solution/