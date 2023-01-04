/*
https://leetcode.com/problems/rearrange-array-elements-by-sign/

You are given a 0-indexed integer array nums of even length consisting of 
an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array 
follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because 
they do not satisfy one or more conditions.  



Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
*/

/*
We know that all positive numbers will be on multiple of 2 indexes(0,2,4..) 
and negatives will be on odd(1,3,5...) indexes.

1 <= |nums[i]| <= 105  -> so no Zero
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 0);
        
        int indexPos = 0, indexNeg = 1;
        
        for(auto num : nums){
            
            if(num > 0){
                ans[indexPos] = num;
                indexPos += 2;
            }
            else if(num < 0){
                ans[indexNeg] = num;
                indexNeg += 2;
            }
        }
        
        return ans;
    }
};