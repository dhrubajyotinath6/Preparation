Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

/*
https://leetcode.com/problems/contains-duplicate/discuss/60858/Possible-solutions.
https://leetcode.com/problems/contains-duplicate/discuss/60898/Single-line-C%2B%2B-solution-60ms

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> hashSet; 
        
        for (int num : nums) {
            if(hashSet.count(num)) return true;
            hashSet.insert(num);
        }
        return false;
    }
};




