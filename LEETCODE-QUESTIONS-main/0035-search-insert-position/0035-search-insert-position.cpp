class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(nums.size() <= 0) return 0;
        if(nums.size() == 1) return nums[0] >= target ? 0 : 1;
        
        if(nums[0] > target) return 0;
        if(nums[nums.size()-1] < target) return nums.size();
        
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] < target){
               //1 3 5 6 , insert 4
                low = mid + 1;
            } 
            
            else if(nums[mid] > target){
                //1 3 5 6 , insert 4
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

/*
Your input
[1]
0

Output
0

Expected
0

--------
Input
[1]
1

Output
1

Expected
0

*/

/*
1   2   3   5   6   7, target = 4;

low = 3, high = 5 => mid = 2+3/2 = 2 

0    1    2    3    5    6    7, target = 4

low = 5, high = 6 => mid = 4+5/2 = 4, high = 4

*/