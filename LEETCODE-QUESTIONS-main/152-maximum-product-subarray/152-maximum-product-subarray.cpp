class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        
        int res = max_so_far;
        
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            
            int temp = max(curr, max(max_so_far*curr, min_so_far*curr));
            
            min_so_far = min(curr, min(max_so_far*curr, min_so_far*curr)); 
            
            max_so_far = temp;
            
            res = max(res, max_so_far);
        }
        
        return res;
    }
};

/*

tc - O(N)
sc - O(1)
*/