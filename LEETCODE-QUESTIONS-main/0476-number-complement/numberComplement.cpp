//https://leetcode.com/problems/number-complement/solution/ -very imp
class Solution {
public:
    int findComplement(int num) {
        
        int todo = num, bit = 1;
        
        while(todo != 0){
            
            //flip the current bit
            num = num ^ bit;
            
            //prepare for nexr run
            bit = bit << 1;
            todo = todo >> 1;
        }
        return num;
    }
};
