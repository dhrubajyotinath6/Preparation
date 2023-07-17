class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mpp;
        
        for(auto i : nums1){
            mpp[i]++;
        }
        
        vector<int> res;
        
        
        for(auto i : nums2){
            if(mpp[i]-- > 0) res.push_back(i);
        }
        
        return res;
    }
};