//https://leetcode.com/problems/arranging-coins/solution/

class Solution {
public:
    int arrangeCoins(int n) {
        
        long left = 0, right = n;
        long mid, coinsNeeded, ans;
        
        while(left <= right){
            mid = left + (right-left)/2;
            
            coinsNeeded = mid * (mid+1)/2;
            
            if(coinsNeeded > n){
                right = mid - 1;
            }
            else{
                left = mid + 1;
                ans = mid;
            }
        }
        
        //what to return ??
        return (int)ans;
    }
};