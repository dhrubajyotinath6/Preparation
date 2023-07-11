You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45



/*
class Solution {
public:
    int climbStairs(int n) {
        
        return count(n);
        
    }
    
    int count(int n){
        
        if(n == 0) return 1;
        
        if(n == 1) return 1;
        
        if(n == 2) return 2;
        
        int take1Step = count(n-1);
        int take2Step = count(n-2);
        
        return take1Step + take2Step;
    }
};
*/

/*
class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        return count(n, dp);
        
    }
    
    int count(int n, vector<int> &dp){
        
        if(n == 0) return 1;
        
        if(n == 1) return 1;
        
        if(n == 2) return 2;
        
        if(dp[n] != -1) return dp[n];
        
        int take1Step = count(n-1, dp);
        int take2Step = count(n-2, dp);
        
        return dp[n] = take1Step + take2Step;
    }
};
*/

/*
class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        return count(n, dp);
        
    }
    
    int count(int n, vector<int> &dp){
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i < dp.size(); i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[dp.size()-1];
    }
};
*/

class Solution {
public:
    int climbStairs(int n) {

        return count(n);        
    }
    
    int count(int n){
        
        int oneStepBack = 2, twoStepBack = 1, temp;
        
        if(n < 3) return n;
        
        for(int i = 3; i <= n ; i++){
            temp = oneStepBack + twoStepBack;
            twoStepBack = oneStepBack;
            oneStepBack = temp;
        }
        
        return oneStepBack;
    }
};
