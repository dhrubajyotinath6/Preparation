Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.


/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/82269/Short-Python-C%2B%2B
https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/82263/C%2B%2B-hash-table-solution-and-sort-%2B-two-pointers-solution-with-time-and-space-complexity

*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mpp;
        
        for(int i : nums1) mpp[i]++;
        
        vector<int> result;
        
        for(int j : nums2)
            if(mpp[j]-- > 0) result.push_back(j);
        
        return result;
    }
};

