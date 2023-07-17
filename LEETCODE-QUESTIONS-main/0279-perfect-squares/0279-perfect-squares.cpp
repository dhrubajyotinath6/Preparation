/*
To summarise:
Approach 1. vanilla recursion
Approach 2. recursion with caching but converted into bottom up dp
Approach 3. Iteratively deepening DFS on an n-ary tree
Approach 4. BFS on an n-ary tree
Approach 5. :)

WATCH TECHDOSE VIDEOS 
*/
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