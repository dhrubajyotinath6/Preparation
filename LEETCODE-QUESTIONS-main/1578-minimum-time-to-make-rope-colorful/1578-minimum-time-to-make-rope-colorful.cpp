/*
https://leetcode.com/problems/minimum-time-to-make-rope-colorful/discuss/831588/JavaC%2B%2BPython-Straight-Forward

*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int ans = 0, sumCost = 0, maxCost = 0, n = neededTime.size();
        
        for(int i = 0; i < n; i++){
            
            if(i > 0 && colors[i] != colors[i-1]){
                
                ans += sumCost - maxCost;
                sumCost = 0;
                maxCost = 0;
            }
            
            sumCost += neededTime[i];
            maxCost = max(maxCost, neededTime[i]);
        }
        
        ans += sumCost - maxCost;
        return ans;
    }
};