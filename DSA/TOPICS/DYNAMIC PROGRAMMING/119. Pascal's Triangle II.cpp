Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33

/*

//https://leetcode.com/problems/pascals-triangle-ii/solution/ --VERY IMP


//APPROACH 1
/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> curr, prev = {1};
        
        for(int i = 1; i <= rowIndex; i++){
            
            curr.assign(i+1,1);
            
            for(int j = 1; j < i; j++){
                curr[j] = prev[j-1] + prev[j];
            }
            
            prev = move(curr);  //This is O(1)
        }
        
        return prev;
    }
};

TC -> O(k^2)
SC -> o(2k)
*/


//APPROACH 2

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans = vector<int>(rowIndex + 1, 1);
        
        if(rowIndex == 0) return ans;
        
        for(int i = 1; i <= rowIndex; i++){
            //exclude last nd first in that row
            for(int j = i-1; j > 0; j--){
                ans[j] += ans[j-1];    // ans[j] = ans[j-1] + ans[j]
            }
        }
       
        return ans;
    }
};

TC -> O(k^2)
SC -> o(k)



//APPROACH 3
class Solution {
 public:
  vector<int> getRow(int n) {
    vector<int> ans = {1};

    for (int k = 1; k <= n; k++)
      ans.push_back((int)((ans.back() * (long long)(n - k + 1)) / k));

    return ans;
  }
};

/*
TC -> O(k)
SC -> o(k)
*/



