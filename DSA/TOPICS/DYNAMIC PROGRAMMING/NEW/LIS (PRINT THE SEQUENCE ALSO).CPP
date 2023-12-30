#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int findLISLength(const vector<int> &nums) {

    if(nums.size() == 0) return 0;
    
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
          
        if (nums[i] > nums[j] && dp[0][i] <= dp[0][j]) {
            
          dp[1][i] = j;
          dp[0][i] = dp[0][j] + 1;
          
         
          if(dp[0][i] > maxLength){
              maxLength = dp[0][i];
              index = i;
          }
          
        }
        
      }
    }
   
    /*
    printing the sequence too
    -4      10      3      7        15
     1      2       2      3        4     --> length  dp[0]
     0      0       0      2        3     --> prev index
     
     maximum length = 4;
     15   7     3    -4
    */
    
    vector<int> ans;
    while(index != dp[1][index] && index != -1){
        ans.push_back(nums[index]);
        index = dp[1][index];
    }
    
    if(index >= 0){
        ans.push_back(nums[index]);
    }

    if(index == -1){
        ans.push_back(nums[0]);
    }
    
    for(auto& x : ans){
        cout << x << " ";
    }
    cout << endl;
    
    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  Solution *lis = new Solution();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lis->findLISLength(nums) << endl;
//   nums = vector<int>{-4, 10, 3, 7, 15};
//   cout << lis->findLISLength(nums) << endl;

  delete lis;
}