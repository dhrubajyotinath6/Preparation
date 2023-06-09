//https://leetcode.com/problems/two-city-scheduling/


Given a string s which consists of lowercase or uppercase letters, 
return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

// https://www.youtube.com/watch?v=vtNoP43hGJA&list=PLEJXowNB4kPxxaPCDVrZhSvW3NSD6ATaS&index=3



class Solution {
    
static bool comparator(vector<int>& a,vector<int>& b){
    
        return a[1]-a[0] > b[1]-b[0];
    }
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        sort(costs.begin(),costs.end(),comparator);
        int ans = 0;
        for(int i=0;i<n;++i)
            ans += i>=n/2?costs[i][1]:costs[i][0];
        
        return ans;
    }
};