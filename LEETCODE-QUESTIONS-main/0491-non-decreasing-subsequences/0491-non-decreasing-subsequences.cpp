class Solution {
    
public:
    void dfs(vector<vector<int>> &res,  vector<int> &seq, vector<int>& nums, int index){
        
        if(seq.size() >= 2){
            res.push_back(seq);
            
        }
        
        unordered_set<int> seen;
        for(int i = index; i < nums.size(); i++){
            
            // if(i > index && nums[i-1] == nums[i]) continue;
            
            if((seq.empty() || seq.back() <= nums[i]) && seen.find(nums[i]) == seen.end()){
                                
                seq.push_back(nums[i]);
                seen.insert(nums[i]);
                dfs(res, seq, nums, i + 1);
                seq.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> suq;
        
        dfs(res, suq, nums, 0);
        return res;
    }
};

/*
https://leetcode.com/problems/non-decreasing-subsequences/discuss/97124/C%2B%2B-dfs-solution-using-unordered_set

The unordered_set is used to avoid [4,6,7(1)] and [4,6,7(2)] in a same level when we dfs. But it will 
not skip [4,6,7(1),7(2)], because 7(2) is added in the next dfs level of [4,6,7(1)]. Every time we 
start a "next level dfs", we will initialize a new unordered_set.

*/