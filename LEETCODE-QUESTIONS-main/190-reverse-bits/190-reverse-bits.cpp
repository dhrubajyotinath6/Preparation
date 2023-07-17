class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t rev = 0, power = 31;
        
        while(n != 0){
            rev += (n & 1) << power;
            n = n >> 1;
            power -= 1;
        }
        
        return rev;
    }
};

/*
TC - O(1)
SC - O(1)
*/