You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

 

Example 1:


Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
 

Constraints:

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10




//CHECK BETTER APPROACH
//https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/490316/JavaC%2B%2BPython3-DP-O(nd)-Solution

//CHECK LC DISCUSSION SECTION TOO

class Solution {
    
public:
    int calculateCost(vector<int> &arr, int i, int j){
        
        int maxi = INT_MIN;
        
        for(int start = i; start <= j; start++){
            maxi = max(maxi, arr[start]);
        }
        
        return maxi;
    }
    
public:
    int f(vector<int> &jobDifficulty, int partition, int start, int end, vector<vector<int>> &dp){
        
        
        if(dp[partition][start] != -1){
            return dp[partition][start];
        }
        //base case start
        if(partition == 0){
            return  dp[partition][start] = calculateCost(jobDifficulty, start, end);
        }
        
        int remainingJob = end - start + 1;
        int partitionPossible = remainingJob - 1;
        
        if(partition > partitionPossible){
            return dp[partition][start] = INT_MAX;
        }
        
        //base case end
        
        /*
        [A, B, C,  |6, 5, 4,| 3, 2, 1]
         0  1  2   |3  4  5,| 6  7  8  
         
         start = 3, end = 8
        */
        int cost = INT_MAX;
        
        for(int i = start; i < end; i++){
            
            int remainingJobCost = f(jobDifficulty, partition - 1, i+1, end, dp);
            
            if(remainingJobCost != INT_MAX){
                cost =  min(cost, calculateCost(jobDifficulty, start, i)  + remainingJobCost);
            }
            
        }
        
        return  dp[partition][start] = cost;
        
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        
        if(d > n) return -1;
        
        vector<vector<int>> dp(d,vector<int>(n, -1));
        
        int ans = f(jobDifficulty, d-1, 0, n-1, dp);
        return ans;
    }
};