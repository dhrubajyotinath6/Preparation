An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690


/*
class Solution {
  
    
// public:
//     bool ugly(int n){
        
//         if(n == 1) return true;
        
//         while(n % 2 == 0){
//             n /= 2;
//         }
        
//         while(n % 3 == 0){
//             n /= 3;
//         }
        
//         while(n % 5 == 0){
//             n /= 5;
//         }
        
//         return n == 1;
//     }
    
public:    
      bool isUgly(int n) {
        
        if(n <= 0) return false; 
        
        for(int i = 2; i <= 5; i++){
            while(n % i == 0){
                n = n / i;
            }
        }
        return n == 1;
    }
    
public:
    int nthUglyNumber(int n) {
        
        int cnt = 0;
        int i = 1;
        
        while(cnt < n){
            if(isUgly(i)){
                cnt++; 
                if(cnt == n) return i;
            }
            i++;
            
            
        }
        
        return 0;
    }
};
*/

//https://leetcode.com/problems/ugly-number-ii/discuss/3235848/Best-C%2B%2B-3-Solution-oror-DP-oror-Tabulation-oror-Hash-Table-oror-Math-oror-One-Stop-Solution.

//https://leetcode.com/problems/ugly-number-ii/discuss/69364/My-16ms-C%2B%2B-DP-solution-with-short-explanation

class Solution {
  
public:
    int nthUglyNumber(int n) {
        

        vector<int> dp(n);
        
        dp[0] = 1;
        
        //for 2,   for 3,  for 4
        int x = 0, y = 0,  z = 0;
        
        for(int i = 1; i < n; i++){
            dp[i] = min(dp[x]*2, min(dp[y]*3, dp[z]*5));
            
            if(dp[i] == dp[x]*2) x++;
            if(dp[i] == dp[y]*3) y++;
            if(dp[i]  == dp[z]*5) z++;
        }
        
        return dp[n-1];
        
        return 0;
    }
};