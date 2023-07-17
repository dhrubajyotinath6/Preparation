class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        auto [mini, maxi] = minmax_element(nums.begin(), nums.end());
        
        int swaps = (mini - nums.begin()) + (nums.end() - maxi - 1);
        
        if(mini > maxi) swaps--;
        return swaps;
    }
};