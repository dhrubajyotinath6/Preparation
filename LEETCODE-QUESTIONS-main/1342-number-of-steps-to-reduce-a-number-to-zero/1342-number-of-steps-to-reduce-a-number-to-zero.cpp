//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/solution/   -- VERY IMP
class Solution {
public:
    int numberOfSteps(int num) {
        
        if(num == 0) return 0;
        
        int steps = 0;
        
        for(int powerOfTwo = 1; powerOfTwo <= num; powerOfTwo = powerOfTwo*2){
            
           // if((powerOfTwo & num) == 1) steps += 2; //-> doesnot work
            if((powerOfTwo & num) != 0) steps += 2;
            
            else steps += 1;
        }
        
        return steps - 1;
    }
};