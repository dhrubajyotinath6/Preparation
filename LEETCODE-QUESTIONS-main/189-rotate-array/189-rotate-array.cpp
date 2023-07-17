class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size() <= 1) return;
        
        k = k % nums.size();
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/*
Your input
[-1]
2

Output
[-1]

Expected
[-1]

*/