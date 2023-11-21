You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109


/*
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

Let's denote x = nums[i] and y = nums[j] and rewrite the formula:

x + rev(y) == y + rev(x)

Now, let's rearrange the formula so that all terms involving x are on one side and all terms involving y are on the other:

x - rev(x) == y - rev(y)

We have simplified the problem. As you can see, for a given num, we are interested in num - rev(num). Let's define a new array arr with the same length as nums where:

arr[i] = nums[i] - rev(nums[i])

Now, the problem becomes "how many pairs in arr are equal?"

*/


class Solution {
    
public:
    int rev(int num){
        int res = 0;
        
        while(num > 0){
            int digit =  num % 10;
            res = (res * 10) + digit;
            num /= 10;
        }
        
        return res;
    }
public:
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++){
            arr[i] = nums[i] - rev(nums[i]);
        }
        
        
        unordered_map<int,int> mpp;
        int ans = 0,  mod = 1e9 + 7;
        
        for(auto& num : arr){
            ans = (ans + mpp[num]) % mod;
            mpp[num]++;
        }
        
        return ans;
    }
};