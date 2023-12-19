Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

 

Example 1:

Input: n = 3
Output: 3
Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 

//https://leetcode.com/problems/nth-digit/discuss/88369/0ms-C%2B%2B-Solution-with-Detail-Explanation
class Solution {
    
public:
    int findDigits(int num, int i){
        return to_string(num)[i-1] - '0';
    }

    
public:
    int findNthDigit(int n) {
        
        /*
        n = 250
        
        target = 250 - 9 - 180 = 61
        digits = 3
        */
        long base = 9, digits = 1;
        while (n - base * digits > 0){
            n -= base * digits;
            base *= 10;
            digits ++;
        }
        
        int target = n;
        
        /*
        100   101   102   103    104    105  ......... 119     120     121
        1-3   3-6   7-9   10-12  13-15  16-18          58-60   61-63   64-66    
        
        61/3 = 20, rem = 1
        
        suppose if 60, then possibleNumber = 20; rem = 0
        */
        int possibleNumber = target/digits;
        int rem = target % digits;
        
        if(rem == 0){
            // number = 100 + (20-1) = 119
            int number = pow(10, digits - 1) + (possibleNumber - 1);
            
            //9 in 119 is our answer  (ie last digit in 119)
            int ans = number % 10;
            return ans;
            
        }else{
            // ans = 100 + 20 
            int number = pow(10, digits - 1) + possibleNumber;
            
            int ans = findDigits(number, rem);
            return ans;
        }
        
      return 0; 
    }
};

