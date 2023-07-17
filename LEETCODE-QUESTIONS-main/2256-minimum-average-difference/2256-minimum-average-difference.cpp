/*

2       5       3       9       5       3
2       7       10      19      24      27
0       1       2       3       4       5

here n = 6
*/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       
        long long prefixSum = 0;
        
        long long totalSum = 0;
        for(auto& num : nums){
            totalSum += num;
        }
        
        int n = nums.size();
        int minAvgDiff = numeric_limits<int>::max();
        int ans = -1;
        
        for(int i = 0; i < nums.size(); i++){
            
            prefixSum += nums[i];
            
            long long leftPartAverage = prefixSum;
            leftPartAverage /= (i + 1);
            
            long long rightPartAverage = totalSum - prefixSum;
            
            if(i != n-1){
                rightPartAverage /= (n - i - 1);
            }
            
             int currDifference = int(abs(leftPartAverage - rightPartAverage));
            
            if(currDifference < minAvgDiff){
                minAvgDiff = currDifference;
                ans = i;
            }
           

        }
        
        return ans;
        
    }
};