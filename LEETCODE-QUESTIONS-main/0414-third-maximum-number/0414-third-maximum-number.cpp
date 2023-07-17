/*
CHECK CONSTRAINTS

https://leetcode.com/problems/third-maximum-number/solution/
APPROACH 4, 5

CHECK APPROACH 5 ->imp
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
    //firstMax, secondMax, and thirdMax, to a value less than the minimum possible integer in the array 
        
        long long firstMax = numeric_limits<long long>::min();;
        long long secondMax = numeric_limits<long long>::min();;
        long long thirdMax = numeric_limits<long long>::min();;
        
        for(auto &num : nums){
            
            // This number is already used once, thus we skip it.
            if (firstMax == num || secondMax == num || thirdMax == num) {
                continue;
            }
            
            if(num > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            
            else if(num > secondMax){
                thirdMax = secondMax;
                secondMax = num;
            }
            else if(num > thirdMax){
                thirdMax = num;
            }
            
        }
        
        if(thirdMax == numeric_limits<long long>::min()){
            return firstMax;
        }
        
        return thirdMax;
    }
};