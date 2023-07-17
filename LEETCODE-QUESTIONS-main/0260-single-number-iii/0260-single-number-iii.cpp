class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n1xn2 = 0;
        for(auto& num : nums){
            n1xn2 ^= num;
        }
        
        int rightMostSetBit = 1;
        while((rightMostSetBit & n1xn2) == 0){
            rightMostSetBit = rightMostSetBit << 1;
        }
        
        int num1 = 0, num2 = 0;
        for(auto& num : nums){
            if((num & rightMostSetBit) != 0){
                //the bit is set
                num1 ^= num;
            }else{
                num2 ^= num;
            }
        }
        
        return vector<int>{num1, num2};
    }
};