A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
Example 2:

Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
 

Constraints:

1 <= n <= 105
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.




//https://leetcode.com/problems/super-ugly-number/discuss/277313/My-view-of-this-question-hope-it-can-help-you-understand!!!   --check this too
/*
tc - O(nk) ; k = primes.length
sc - O(n + k)
*/

#define ll long long int

class Solution {
    
public:
    ll minFunc(ll a, ll b){
        if(a < b) return a;
        return b;
    }
    
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<ll> pointers(primes.size(), 0);
        
        vector<ll> dp(n, 0);
        dp[0] = 1;
        
        for(int i = 1; i < n; i++){
            
            int mini = INT_MAX;
            
            for(int i = 0; i < pointers.size(); i++){
                mini =  minFunc(mini, dp[pointers[i]] * primes[i]);
            }
            
            for(int i = 0; i < pointers.size(); i++){
                if(mini == dp[pointers[i]]*primes[i]){
                   pointers[i]++; 
                }
            }
            
            dp[i] = mini;
        }
        
        int ans = dp[n-1];
        return ans;
        
    }
};