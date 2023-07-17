/*
a, b, c, d -> x
a, b, c, d, e -> x+1

*/
/*
// Better Brute Force
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int count = 0;
        
        for (int s = 0; s < nums.size() - 2; s++) {
            
            int d = nums[s + 1] - nums[s];
            
            for (int e = s + 2; e < nums.size(); e++) {
                if (nums[e] - nums[e - 1] == d)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};
*/

/*
//Recursion
class Solution {
    int sum = 0;
public:
    int numberOfArithmeticSlices(vector<int>& nums) {       
       
        slices(nums, nums.size() - 1);
        return sum;
    }
    
public:
    int slices(vector<int>& nums, int i) {
        
        if (i < 2)
            return 0;
        int ap = 0;
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            ap = 1 + slices(nums, i - 1);
            sum += ap;
        } else
            slices(nums, i - 1);
        return ap;
    }
};
*/

/*
//Dynamic Programming

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<int> dp(nums.size());
        int sum = 0;
        
        for (int i = 2; i < dp.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;          

    }
};

*/


//Constant Space Dynamic Programming
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int dp = 0;
        int sum = 0;
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp = 1 + dp;
                sum += dp;
            } else
                dp = 0;
        }
        return sum;       

    }
};
