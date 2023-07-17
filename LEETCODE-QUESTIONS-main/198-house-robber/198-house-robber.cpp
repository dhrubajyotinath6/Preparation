
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        
        return findMax(nums, 0);
    }
    
    
    int findMax(const vector<int> &nums, int currentIndex) {
        
    if (currentIndex >= nums.size()) {
      return 0;
    }
        
    // steal from current house and skip one to steal next
    int stealCurrent = nums[currentIndex] + findMax(nums, currentIndex + 2);
        
    // skip current house to steel from the adjacent house
    int skipCurrent = findMax(nums, currentIndex + 1);
        
    return max(stealCurrent, skipCurrent);
  }
};
*/

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        return findMax(nums, 0, dp);
    }
    
    
    int findMax(const vector<int> &nums, int currentIndex, vector<int> &dp) {
        
    if (currentIndex >= nums.size()) {
      return 0;
    }
    
    if(dp[currentIndex] != -1) return dp[currentIndex];
    // steal from current house and skip one to steal next
    int stealCurrent = nums[currentIndex] + findMax(nums, currentIndex + 2, dp);
        
    // skip current house to steel from the adjacent house
    int skipCurrent = findMax(nums, currentIndex + 1, dp);
        
    return dp[currentIndex] = max(stealCurrent, skipCurrent);
  }
};
*/

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size() + 1, -1);
        return findMax(nums, dp);
    }
    
    
    int findMax(const vector<int> &nums, vector<int> &dp) {
        
    if(nums.empty() == true) return 0;
        
    dp[0] = 0;  // if there are no houses
        
    dp[1] = nums[0]; // if there are only 1 house
        
    for(int i = 2; i < dp.size(); i++){
        dp[i] = max(nums[i - 1] + dp[i-2], dp[i-1]);
    }
    
        
    return dp[dp.size() - 1];
  }
};
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        return findMax(nums);
    }
    
    
    int findMax(const vector<int> &nums) {
        
    if(nums.empty() == true) return 0;
        
    int n1 = 0;  // if there are no houses
        
    int n2 = nums[0]; // if there are only 1 house
        
    int temp;
        
    for(int i = 2; i < nums.size() + 1; i++){
        
        int temp = max(nums[i - 1] + n1, n2);
        
        n1 = n2;
        n2 = temp;
    }
    
        
    return n2;
  }
};



