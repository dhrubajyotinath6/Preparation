Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        
        int res = max_so_far;
        
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            
            int temp = max(curr, max(max_so_far*curr, min_so_far*curr));
            
            min_so_far = min(curr, min(max_so_far*curr, min_so_far*curr)); 
            
            max_so_far = temp;
            
            res = max(res, max_so_far);
        }
        
        return res;
    }
};

/*

tc - O(N)
sc - O(1)
*/