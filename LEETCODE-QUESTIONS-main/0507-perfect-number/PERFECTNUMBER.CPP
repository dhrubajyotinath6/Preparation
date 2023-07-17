A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. 
A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 7
Output: false
  
  
  /*
https://leetcode.com/problems/perfect-number/solution/ -- very imp

check Approach #4 Euclid-Euler Theorem [Accepted]
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if(num <= 0) return false;
        
        int sum = 0;
        
        for(int i = 1; i*i <= num; i++){
            
            if(num % i == 0){
                sum += i;
                
                if(i*i != num){
                    sum += num/i;
                }
            }
        }
        
        // cout << sum << endl;
        
        return sum - num == num;
    }
};

/*
We sum up all such factors and check if the given number is a Perfect 
Number or not. Another point to be observed is that while considering 1 as 
such a factor, numnum will also be considered as the other factor. Thus, we 
need to subtract numnum from the sumsum.

*/
