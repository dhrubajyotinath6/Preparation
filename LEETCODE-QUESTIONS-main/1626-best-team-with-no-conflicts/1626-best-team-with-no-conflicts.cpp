//https://leetcode.com/problems/best-team-with-no-conflicts/discuss/3120806/LeetCode-The-Hard-Way-Explained-Line-By-Line


//https://leetcode.com/problems/best-team-with-no-conflicts/solution/
// check approach 3 : Binary Indexed Tree (BIT) / Fenwick Tree

class Solution {
public:
    
   
    int dfs(vector<vector<int>> &dp, vector<pair<int,int>>& g, int i, int prevIndex) {
       
        if (i >= g.size()) return 0;
       
        if (dp[prevIndex + 1][i] != -1) return dp[prevIndex + 1][i];
       
        //we are skipping
        int res = dfs(dp, g, i + 1, prevIndex);
        
        //checking we can include or that. if we can, calculating it and taking the max
        if (prevIndex == -1 || g[i].second >= g[prevIndex].second) res = max(res, g[i].second + dfs(dp, g, i + 1, i));
        
        return dp[prevIndex + 1][i] = res;
    }
    
   int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        vector<vector<int>> dp(scores.size(), vector<int>(scores.size(), -1));
       
        vector<pair<int, int>> g;
        for (int i = 0; i < scores.size(); i++) {
            g.push_back({ages[i]+1, scores[i]});
        }
       
        sort(g.begin(), g.end());
        return dfs(dp, g, 0, -1);
    }
};