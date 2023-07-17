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
/*
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
*/


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

