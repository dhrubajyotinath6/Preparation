Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1


//https://leetcode.com/problems/4sum-ii/discuss/1740606/Going-from-O(N4)-greater-O(N3)-greater-O(N2)-JavaC%2B%2B

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        map<int,int> freqMap;
        
        for(int k : nums3)
            for(int l : nums4)
                freqMap[l+k]++;
        
        int count = 0;
        
        for(int i : nums1)
            for(int j : nums2)
                count += freqMap[-(i + j)];
        
        return count;
    }
};

