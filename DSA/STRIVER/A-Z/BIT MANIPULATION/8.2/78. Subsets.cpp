//https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

class Solution {
    
private:
    
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        
        ans.push_back(ds);
        
        for(int i = ind; i < nums.size(); i++){
            
            if(i != ind && nums[i] == nums[i -1]) continue;
            ds.push_back(nums[i]);
            
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        sort(nums.begin(), nums.end());
        
        findSubsets(0, nums, ds, ans);
        
        return ans;
    }
};

