Given an array of distinct integers nums and a target integer target, return the number of 
possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
 

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? 
What limitation we need to add to the question to allow negative numbers?




/*
same as coin change 2

difference is:
 In coin change 2 : (1  1   2)  &&  (1   2   1)    &&   (2   1   1)  counted as 1
 
 But here it is counted as 3

*/

//https://leetcode.com/problems/combination-sum-iv/discuss/85036/1ms-Java-DP-Solution-with-Detailed-Explanation

//https://leetcode.com/problems/combination-sum-iv/discuss/1166177/Short-and-Easy-w-Explanation-or-Optimization-from-Brute-Force-to-DP-Solution

class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<uint> comb(target+1);
        comb[0] = 1;
        
        for(int i = 1; i < comb.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0) comb[i] += comb[i-nums[j]];
            }
        }
        
        return comb[target];
    }
};

//[1,2,3]

// public int combinationSum4(int[] nums, int target) {
//     int[] comb = new int[target + 1];
//     comb[0] = 1;
//     for (int i = 1; i < comb.length; i++) {
//         for (int j = 0; j < nums.length; j++) {
//             if (i - nums[j] >= 0) {
//                 comb[i] += comb[i - nums[j]];
//             }
//         }
//     }
//     return comb[target];
// }