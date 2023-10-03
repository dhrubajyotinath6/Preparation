//https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() <= 0) return -1;
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
        
        int low = 0, high = nums.size();
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] < target) low = mid + 1;
            
            else if(nums[mid] > target) high = mid - 1;
        }
        
        return -1;
    }
};