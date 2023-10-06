Given an integer n, break it into the sum of k positive integers, where k >= 2, 
and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.


/*
can be solved using dp but there are 2 maths solution

*/
class Solution {
public:
    int integerBreak(int n) {
        
        if(n <= 3){
            return n-1;
        }
        
        
        if(n % 3 == 0){
            return pow(3, n/3);
        }
        
        if(n % 3 == 1){
            return pow(3, n/3 -1)*4;
        }
        
        return pow(3, n/3)*2;
    }
};


//Approach 3: Mathematics
/*

Interestingly, it is optimal to only split n into 2 and 3

Algorithm

1. If n <= 3, then return n - 1.
2. Initialize ans = 1.
3. While n > 4:
        Multiply ans by 3.
        Subtract 3 from n.
4.Return ans * n.

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        
        return ans * n;
    }
};

tc -> O(n/3) = O(n)
sc -> O(1)

*/


//Approach 4: Equation
/*

Instead of manually multiplying by 3 repeatedly, we can use math to figure out how many 3s and 2s will make up the optimal product.

First, we will again consider the cases when n <= 3 separately.

Now, for n > 3, we have three possibilities:

1. n % 3 == 0. If n is divisible by 3, then we can simply just break it into n/3*3s
 
2. n % 3 == 1. If we were to break n into n/3 3s,  we would have a remainder of 1. As mentioned in the previous approach, it would be better to combine this 1 with one of the 3s to form a sum of 4, which we can break into 2 * 2. In this case, we break n into n/3 - 1 3s. and two 2s

3. n % 3 == 2. If we were to break n into n/3 3s, we would have a remainder of 2. We simply break n into n/3 3s and a single 2.


class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        
        if (n % 3 == 1) {
            return pow(3, n / 3 - 1) * 4;
        }
        
        return pow(3, n / 3) * 2;
    }
};

tc -> O(logn) It may seem that this algorithm runs in  O(1) but exponentiation costs 
      O(logn)

O(logn).
sc -> O(1)

*/