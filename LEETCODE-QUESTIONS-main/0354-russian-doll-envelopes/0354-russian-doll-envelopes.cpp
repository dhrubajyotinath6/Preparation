/*
// binary search solution: O(nlogn)
// width is increasing, but if two widths are the same, the height is decreasing
// after sorting, all envolopes are valid 'based on width', so we just binary search based on 'heights'
// to choose 'some of them' to meet the requirement
// Ex. after sorting: (1,3), (3,5), (6,8), (6,7), (8,4), (9,5)
// transform to question find LIS: [3,5,8,7,4,5] => like '300. Longest Increasing Subsequence'

*/

class Solution {
    
public: 
    //n^2
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size());
        dp[0] = 1;

        int maxLength = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            
          dp[i] = 1;
            
          for (int j = 0; j < i; j++) {              
            if (nums[i] > nums[j] && dp[i] <= dp[j]) {
              dp[i] = dp[j] + 1;
              maxLength = max(maxLength, dp[i]);
            }              
          }
            
       }
        return maxLength;
    }
    

public: 
    //n^2
    int modifiedLengthOfLIS(vector<vector<int>>& nums) {
        
        vector<int> dp(nums.size());
        dp[0] = 1;

        int maxLength = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            
          dp[i] = 1;
            
          for (int j = 0; j < i; j++) {              
            if (nums[i][1] > nums[j][1] && dp[i] <= dp[j]) {
              dp[i] = dp[j] + 1;
              maxLength = max(maxLength, dp[i]);
            }              
          }
            
       }
        return maxLength;
    }
 
//https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Segment-Tree-Solutions-Picture-explain-O(NlogN)
public:
    //(nlogn)    
    int LIS(vector<int> nums){
        vector<int> sub;
        
        for(auto& num : nums){
            if(sub.empty() || sub[sub.size() - 1] < num){
                sub.push_back(num);
            }else{
                auto it = lower_bound(sub.begin(), sub.end(), num); // Find the index of the first element >= x
                *it = num;
            }
        }
        
        return sub.size();
    }
    

public:
    //(nlogn)    
    int ModifiedLIS(vector<vector<int>>& nums){
        vector<int> sub;
        
        for(auto& num : nums){
            if(sub.empty() || sub[sub.size() - 1] < num[1]){
                sub.push_back(num[1]);
            }else{
                auto it = lower_bound(sub.begin(), sub.end(), num[1]); // Find the index of the first element >= x
                *it = num[1];
            }
        }
        
        return sub.size();
    }
    
    
public:
    //comparison
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       sort(envelopes.begin(), envelopes.end(), comp); 
    
    
    /*
    Ex. after sorting: (1,3), (3,5), (6,8), (6,7), (8,4), (9,5)
    find LIS: [3,5,8,7,4,5]    
    */
    
    int ans = ModifiedLIS(envelopes);
    return ans;   
    
}
    
};