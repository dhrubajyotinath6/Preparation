class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int windowSum = 0, maxSum = 0;
        int windowStart = 0;
        
        unordered_map<int,int>count;
        
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
           
            int currElement = nums[windowEnd];
            count[currElement]++;
            
            windowSum += currElement;
            while(windowStart < windowEnd && count[currElement] > 1){
                count[nums[windowStart]]--;
                windowSum -= nums[windowStart++];
            }
            
            maxSum = max(maxSum, windowSum);
            
        }

        return maxSum;
    }
};