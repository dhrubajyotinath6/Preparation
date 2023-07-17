//https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Exponential_identity   -- very very imp

// https://leetcode.com/problems/sqrtx/solution/

/*

Approach 2: Binary Search  -- also see this

*/


class Solution {
    
    const double e = std::exp(1.0);
    
public:
    int mySqrt(int x) {
        
    if (x < 2) return x;

    int left = (int)pow(e, 0.5 * log(x));
        
    int right = left + 1;
    return (long)right * right > x ? left : right;
    }
};