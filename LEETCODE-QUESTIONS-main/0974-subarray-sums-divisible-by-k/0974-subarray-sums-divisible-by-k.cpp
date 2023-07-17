//https://leetcode.com/problems/subarray-sums-divisible-by-k/solution/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        int prefixMod = 0, res = 0;
        
        vector<int> modGroups(k);
        modGroups[0] = 1;
        
        for(auto& num : nums){
            // Take modulo twice to avoid negative remainders.
            prefixMod = (prefixMod + num % k + k) % k;
            res += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }
        
        return res;
    }
};