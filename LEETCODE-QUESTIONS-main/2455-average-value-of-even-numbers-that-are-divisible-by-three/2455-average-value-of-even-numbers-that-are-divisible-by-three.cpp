class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        long long sum = 0;
        int count = 0;
        
        for(auto& num : nums){
            if(num % 2 == 0 && num % 3 == 0){
                sum += num;
                count++;
            }
        }
        
        if(count == 0) return 0;
        
        return (int)sum/count;
    }
};