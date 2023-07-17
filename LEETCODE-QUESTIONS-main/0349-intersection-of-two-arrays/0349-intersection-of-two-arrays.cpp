/*
https://leetcode.com/problems/intersection-of-two-arrays/solution/245850   --very imp

This is a Facebook interview question.
They ask for the intersection, which has a trivial solution using a hash or a set.

Then they ask you to solve it under these constraints:
O(n) time and O(1) space (the resulting array of intersections is not taken into consideration).
You are told the lists are sorted.

Cases to take into consideration include:
duplicates, negative values, single value lists, 0's, and empty list arguments.
Other considerations might include
sparse arrays.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> m(nums1.begin(), nums1.end());        
        vector<int> res;
        
        // for (auto a : nums2)
        //     if (m.count(a)) {
        //         res.push_back(a);
        //         m.erase(a);
        //     }
        // return res;
        
        for (auto a : nums2)
            if (m.erase(a)) {
                res.push_back(a);
            }
        return res;
    }
};