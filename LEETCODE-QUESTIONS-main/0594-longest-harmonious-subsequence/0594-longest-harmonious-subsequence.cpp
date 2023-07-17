//https://leetcode.com/problems/longest-harmonious-subsequence/solution/

//Approach 5: In Single Loop -check this

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int> map;
        
        for(auto &num : nums){
            map[num]++;
        }
        
        int res = 0;
        
        for(auto [key, value] : map){
            
            if(map.find(key+1) != map.end()){
                res = max(res, map[key] + map[key+1]);
            }
        }
        
        return res;
    }
};