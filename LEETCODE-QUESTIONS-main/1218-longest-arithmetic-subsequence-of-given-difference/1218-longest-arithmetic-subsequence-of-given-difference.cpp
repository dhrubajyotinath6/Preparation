class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int> dp;
        int ans = 1;
        
        for(auto& b : arr){
            
            /*
            a, b, c , d......
            
              d = b - a
            =>a = b - d
            
            */
            
            int a = b - difference;
            
            int freq = dp.count(a) ? dp[a] : 0;
            dp[b] = freq + 1;
            ans = max(ans, dp[b]);
        }
        
        return ans;
    }
};