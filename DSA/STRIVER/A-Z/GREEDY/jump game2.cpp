//

//DP SOLUTION
class Solution {
public:
    int jump(vector<int>& jumps) {
        
       vector<int> dp(jumps.size());

    // initialize with infinity, except the first index which should be zero as we start 
    // from there
    for (int i = 1; i < jumps.size(); i++) {
      dp[i] = numeric_limits<int>::max();
    }

    for (int start = 0; start < jumps.size() - 1; start++) {
      for (int end = start + 1; end <= start + jumps[start] && 
                                      end < jumps.size(); end++) {
        dp[end] = min(dp[end], dp[start] + 1);
      }
    }

    return dp[jumps.size() - 1];
    }
};

//greedy 

