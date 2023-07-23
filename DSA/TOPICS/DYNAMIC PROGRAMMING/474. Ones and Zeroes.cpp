
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.



Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.


Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100


//https://leetcode.com/problems/ones-and-zeroes/discuss/814077/Dedicated-to-Beginners  -- tabulation method needs to understand

//https://leetcode.com/problems/ones-and-zeroes/discuss/814077/Dedicated-to-Beginners
class Solution {
    
public:
    int sub(vector<pair<int,int>> &a, int index, int n, int ones, int zeros, vector<vector<vector<int>>> &dp){
        
        if(index == n or (ones == 0 && zeros == 0)) return 0;
        
        if(dp[index][ones][zeros] != -1) return dp[index][ones][zeros];
        
        
        if(a[index].first > ones || a[index].second > zeros){
            return dp[index][ones][zeros] = sub(a, index + 1, n, ones, zeros, dp);
        }
        
        //include
        int include = 1 + sub(a, index + 1, n, ones - a[index].first, zeros - a[index].second, dp);        
        //exclude
        int exclude =  sub(a, index + 1, n, ones, zeros, dp);
        
        return dp[index][ones][zeros] = max(include, exclude);
        
    }
public:
    int findMaxForm(vector<string>& strs, int zero, int one) {
        
        vector<pair<int,int>> a;
        for(auto& str : strs){
            int one = 0, zero = 0;
            for(auto& ch : str){
                (ch == '1') ? one++ : zero++;
            }
            
            a.push_back({one, zero});
        }
        
        
        vector<vector<vector<int>>> dp(601, vector<vector<int>>(101, vector<int>(101, -1)));
        // int dp[601][101][101] = {};
        // memset(dp, -1, sizeof(dp));
        
        int n = strs.size();
        int ans = sub(a, 0, n, one, zero, dp);
        return ans;
        
    }
};


/*
int dp[601][101][101] = {};
    
    int sub(vector<pair<int,int>> &a, int index , int nOnes , int nZeros)
    {
        int n = a.size();
        if(index == n or (nZeros ==0 and nOnes == 0))   return 0;
        
        // if we already know answer for this index with current nZeros , nOnes then no need to recompute return the saved answer
        if(dp[index][nOnes][nZeros] != -1)
            return dp[index][nOnes][nZeros];
        
        // we dont have available no of zeros or ones to build this curent string, so we dont have any other option but to skip this index
        if(a[index].first > nOnes or a[index].second > nZeros)  
            return dp[index][nOnes][nZeros] = sub(a , index+1 , nOnes , nZeros);
        // NOTE : we are also saving corrensponding values
        
        int include = 1 + sub(a , index+1, nOnes - a[index].first , nZeros - a[index].second);
        int exclude = sub(a , index+1 , nOnes , nZeros);
        
        // save these values and return the answer
        return dp[index][nOnes][nZeros] = max(include , exclude);
    }
    
    int findMaxForm(vector<string>& strs, int nZeros, int nOnes) 
    {
        vector<pair<int,int>> a;
        memset(dp , -1 , sizeof(dp));
        
        for(auto i : strs)
        {
            int one = 0 , zero = 0;
            for(auto j : i)
                (j == '1') ? one ++ : zero++;
            a.push_back({one , zero});
        }
        
        int ans = sub(a , 0 , nOnes , nZeros);
        return ans;
    }

*/