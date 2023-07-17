class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if(nums.size() <= 1) return false;
        
        set<int> hashSet;
        
        for(auto num : nums){
            
            if(hashSet.count(num)) return true;
            
            hashSet.insert(num);
            
        }
        
        return false;
    }
};