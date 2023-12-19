The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

Return the maximum such product difference.

 

Example 1:

Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
Example 2:

Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
 

Constraints:

4 <= nums.length <= 104
1 <= nums[i] <= 104


class Solution {
    
public:
    vector<int> twoMaxiTwoMini(vector<int> &nums){
        
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        int mini1 = INT_MAX, mini2 = INT_MAX;
        
        for(auto& num : nums){
            
            if(num > maxi1){
                maxi2 = maxi1;
                maxi1 = num;
            }else if(num > maxi2){
                maxi2 = num;
            }
            
            
            if(num < mini1){
                mini2 = mini1;
                mini1 = num;
            }else if(num < mini2){
                mini2 = num;
            }
        }
        
        vector<int> ans {maxi1, maxi2, mini1, mini2};
        return ans;
    }
public:
    int maxProductDifference(vector<int>& nums) {
        
        //constant size vector
        vector<int> ans = twoMaxiTwoMini(nums);
        
        cout << ans[0] << endl;
        cout << ans[1] << endl;
        cout << ans[2] << endl;
        cout << ans[3] << endl;
        
        return ans[0]*ans[1] - ans[2]*ans[3];
    }
};