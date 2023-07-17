class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> prefixSum(n);
        
        prefixSum[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        int totalSum = prefixSum[n-1];
        
        
        
        
        // 0    1   2   '3'   4   5
        
        // 1    7   3   '6'   5   6
        // 1    8   11  '17'  22  28
        
        /*
        i = 3
        
        11  = 28 - 11 - 6 = 17 - 6 = 11
        
        */
        // n = 6 -> [1, 4]
        
        if(0 == totalSum - nums[0]) return 0;
        
        
        for(int i = 1; i <= n - 2 ; i++){
            
            if(prefixSum[i-1] == totalSum - prefixSum[i-1] - nums[i]) return i;
        }       
        
        
        if(totalSum - nums[n-1] == 0) return n-1;
        
        return -1;
        
    }
};

/*
Input
[2,1,-1]

Output
-1

Expected
0

--------

Input
[-1,-1,1,1,0,0]
Output
5
Expected
4

*/