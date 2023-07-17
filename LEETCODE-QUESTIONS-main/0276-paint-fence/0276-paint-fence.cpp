class Solution {
public:
    int numWays(int n, int k) {
        
        if(n == 1) return k;
        
        int twoPostsBack = k;
        int onePostsBack = k*k;
        
        for(int i = 3; i <= n; i++){
            int curr = (k-1)* (onePostsBack + twoPostsBack);
            twoPostsBack = onePostsBack;
            onePostsBack = curr;
        }
        
        return onePostsBack;
    }
};