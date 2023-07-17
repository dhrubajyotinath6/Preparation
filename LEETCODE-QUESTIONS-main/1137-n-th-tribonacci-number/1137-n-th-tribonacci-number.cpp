The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537

==>  
    
class Solution {
public:
    int tribonacci(int n) {
        
        if(n < 2) return n;
        
        if(n == 2) return 1;
        
        int n0 = 0, n1 = 1, n2 = 1, temp;
        
        for(int i = 3; i <=  n; i++){
            temp = n0 + n1 + n2;
            n0 = n1;
            n1 = n2;
            n2 = temp;
        }
        
        return n2;
    }
};



// int CalculateFibonacci(int n) {
//     if (n < 2) {
//       return n;
//     }
//     int n1 = 0, n2 = 1, temp;
//     for (int i = 2; i <= n; i++) {
//       temp = n1 + n2;
//       n1 = n2;
//       n2 = temp;
//     }
//     return n2;
//   }
