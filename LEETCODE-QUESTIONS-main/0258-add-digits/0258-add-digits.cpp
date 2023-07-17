//https://leetcode.com/problems/add-digits/solution/
// check approach 2

/*
class Solution {
public:
    int addDigits(int num) {
        
        int digitalRoot = 0;
        
        while(num > 0){
            
            digitalRoot += num % 10;
            num /= 10;
            
            if(num == 0 && digitalRoot > 9){
                // num is zero means one loop complete so assign 
                // digitalRoot to num
                num = digitalRoot;
                digitalRoot = 0;
            }
        }
        
        return digitalRoot;
    }
};
*/

class Solution {
public:
    int addDigits(int num) {
        
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9; 
    }
};


