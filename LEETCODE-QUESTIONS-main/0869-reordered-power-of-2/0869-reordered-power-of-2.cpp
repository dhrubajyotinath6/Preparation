/*
https://leetcode.com/problems/reordered-power-of-2/discuss/1120216/Reordered-Power-of-2-or-Short-and-Easy-w-Explanation-or-Beats-100


Why are we looping from 2^0 to 2^29?

because those are all the possible powers of 2 within the constraints

Because it is said that only 9 digits are to be considered in 
constraints. So 2^29 = 9 digits and 2^30 = 10 digits.

Just use a calculator and count the digits after computing. So 
2^29 is used.
*/

class Solution {
    
public:
    vector<int> countDigits(int n){
        vector<int> digitsInN(10);
        
        while(n){
           digitsInN[n % 10]++;
            n /= 10;
        }
        
        return digitsInN;
    }
public:
    bool reorderedPowerOf2(int n) {
        
        vector<int> digitsInN = countDigits(n);
        
        // powOf2 goes from 2^0 to 2^29 and each time freq of digits in powOf2 is compared with digitsInN
        for(int i = 0, powOf2 = 1; i < 30; i++, powOf2 <<= 1)
            if(digitsInN == countDigits(powOf2)) return true;  // return true if both have same frequency of each digits
        
	return false;
    }
};

