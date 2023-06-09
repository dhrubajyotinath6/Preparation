//https://leetcode.com/problems/largest-number/

Given a list of non-negative integers nums, arrange them such that they form the largest number 
and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109


/*
https://www.cplusplus.com/reference/algorithm/sort/
Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.

https://leetcode.com/problems/largest-number/discuss/53160/Share-a-short-code-in-c%2B%2B
*/


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        //For FAST I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        string ans;

        for(auto num : nums){
            ans += to_string(num);
        }
            return ans[0]=='0' ? "0" : ans;
    }
    
};






