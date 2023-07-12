Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; 
in other words, it is the product of some integer with itself. 

For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104


/*
To summarise:
Approach 1. vanilla recursion
Approach 2. recursion with caching but converted into bottom up dp
Approach 3. Iteratively deepening DFS on an n-ary tree
Approach 4. BFS on an n-ary tree
Approach 5. :)

WATCH TECHDOSE VIDEOS 
*/

Legendre's three-square theorem.
https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem


class Solution {
public:
    int numSquares(int n) {
        
        if(ceil(sqrt(n)) == floor(sqrt(n))){
            return 1;
        }
        
        while(n % 4 == 0){   // 4^a(8b+7)
            n /= 4;
        }
        
        if(n % 8 == 7){      // 8b + 7
            return 4;
        }
        
        for(int i = 1; i*i <= n; i++){
            int base = sqrt(n-i*i);
            if(base*base == (n-i*i))
                return 2;
        }
        
        return 3;
    }
};