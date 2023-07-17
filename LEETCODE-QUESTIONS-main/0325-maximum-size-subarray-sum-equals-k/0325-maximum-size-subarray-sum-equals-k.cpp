/*
if there exists some subarray from i to j summing to  k in nums, then we know that

prefixSum[j] - prefixSum[i] = k 
prefixSum[j] - prefixSum[i] - k = 0
prefixSum[j] - k = prefixSum[i]


*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        long prefixSum = 0;
        long longestSubarray = 0;
        unordered_map<long,long> index;
        
        for(int i = 0; i < nums.size(); i++){
            
            prefixSum += nums[i];
            
            if(prefixSum == k){
                longestSubarray = i + 1;
            }
            
            if(index.find(prefixSum - k) != index.end()){
                // longestSubarray = max(longestSubarray, i - index[prefixSum - k]);
                if(longestSubarray < i - index[prefixSum - k]){
                    longestSubarray = i - index[prefixSum - k];
                }
            }
            
            if(index.find(prefixSum) == index.end()){
                index[prefixSum] = i;
            }
        }
        
        return longestSubarray;
    }
};