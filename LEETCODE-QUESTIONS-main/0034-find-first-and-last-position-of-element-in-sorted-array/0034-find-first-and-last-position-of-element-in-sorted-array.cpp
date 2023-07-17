class Solution {
    
public:
    int f(vector<int> &nums, int target, bool maxIndex){
        
        int keyIndex = -1;
        int start = 0, end = nums.size() - 1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(target == nums[mid]){
                keyIndex = mid;
                
                if(maxIndex){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return keyIndex;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result(2,-1);
        result[0] = f(nums, target, false);
        
        if(result[0] != -1){
            result[1] = f(nums, target, true);
        }
        
        return result;
    }
};