//https://leetcode.com/problems/range-sum-query-immutable/solution/

/*
-2    0    3    -5     2    -1

prefixSum
0     1    2    3     4     5   
-2   -2    1    -4    -2    -3

[2,5] -> (-3) - (-2)
*/

class NumArray {
    
    vector<int> &sum;//`preSum` will reference to `nums` array, no copy at all!
    
public:
    NumArray(vector<int>& nums) : sum(nums){
        
        for(int i = 1; i < nums.size(); i++){
            sum[i] = sum[i-1] + nums[i];
        }
        
    }
    
    int sumRange(int left, int right) {
        
        if(left == 0) return sum[right];
        return sum[right] - sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */