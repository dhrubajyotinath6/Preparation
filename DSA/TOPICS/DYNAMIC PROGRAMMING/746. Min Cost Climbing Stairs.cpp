You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.



Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999


/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        int ans = minimumCost(cost, n);
        
        return ans;
    }
    
    int minimumCost(vector<int>& cost, int i){
        
        if(i <= 1) return 0;
        
        int downOne = cost[i-1] + minimumCost(cost, i - 1);
        int downTwo = cost[i-2] + minimumCost(cost, i - 2);
        
        return min(downOne, downTwo);
    }
};
*/
 
/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        vector<int> dp(n + 1, -1);
        
        int ans = minimumCost(cost, n, dp);
        
        return ans;
    }
    
    int minimumCost(vector<int>& cost, int i, vector<int> &dp){
        
        if(i <= 1) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int downOne = cost[i-1] + minimumCost(cost, i - 1, dp);
        int downTwo = cost[i-2] + minimumCost(cost, i - 2, dp);
        
        return dp[i] = min(downOne, downTwo);
    }
};
*/

/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        vector<int> dp(n + 1, -1);
        
        int ans = minimumCost(cost, n, dp);
        
        return ans;
    }
    
    int minimumCost(vector<int>& cost, int i, vector<int> &dp){
        
       dp[0] = dp[1] = 0;
        
       for(int i = 2; i < dp.size(); i++){
           
           int takeOneStep = dp[i-1] + cost[i-1];
           int takeTwoStep = dp[i-2] + cost[i-2];
           
           dp[i] = min(takeOneStep, takeTwoStep);
       }
        
       return dp[dp.size() - 1];
    }
};
*/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        vector<int> dp(n + 1, -1);
        
        int ans = minimumCost(cost, n, dp);
        
        return ans;
    }
    
    int minimumCost(vector<int>& cost, int i, vector<int> &dp){
        
       int stepOne = 0;
       int stepTwo = 0;
        
       for(int i = 2; i < dp.size(); i++){
           
           int temp =  min(stepOne + cost[i-1], stepTwo + cost[i-2]);
           
           stepTwo = stepOne;
           stepOne = temp;        
        }
        
       return stepOne;
    }
};