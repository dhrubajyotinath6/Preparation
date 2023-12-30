/*
SAME CODE TO LIS (LONGEST INCREASING SEQUENCE)

WHY WE NEED TO SORT ?

ANS: IF WE DONOT SORT
Input:
[5,9,18,54,108,540,90,180,360,720]

Output:
[720,360,180,90,540,108,54,18,9]
Expected:
[9,18,90,180,360,720]


*/

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.



class Solution {
    
public:
 vector<int> f(vector<int> &nums) {
     
     sort(nums.begin(), nums.end());
     
    vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
    
    for(int i = 0; i < nums.size(); i++){
        dp[1][i] = i;
    }
    
    dp[0][0] = 1;

    int maxLength = 1;
    int index = -1;
     
     
    
    for (int i = 1; i < nums.size(); i++) {
        
      dp[0][i] = 1;
      
      for (int j = 0; j < i; j++) {
          
        if ( ( (nums[i] % nums[j]) == 0 || (nums[j] % nums[i]) == 0) && dp[0][i] <= dp[0][j]) {
            
          dp[1][i] = j;
          dp[0][i] = dp[0][j] + 1;
          
         
          if(dp[0][i] > maxLength){
              maxLength = dp[0][i];
              index = i;
          }
          
        }
        
      }
    }
   
     
   
    vector<int> ans;
    while(index != -1 && index != dp[1][index]){
        ans.push_back(nums[index]);
        index = dp[1][index];
    }
    
    
    if(index >= 0){
        ans.push_back(nums[index]);
    }
     
    if(index == -1){
        ans.push_back(nums[0]);
    }
        
    return ans;
  }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 1) return nums;
        return f(nums);
    }
};