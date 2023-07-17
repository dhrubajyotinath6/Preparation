//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        
        int maxPro = 0;
        int n = prices.size() - 1;
        
        while(i < n){
            
            while(i < n && prices[i] >= prices[i+1]) i++;         
            valley = prices[i];
            
            while(i < n && prices[i] <= prices[i+1]) i++;
            peak = prices[i];
            
            maxPro += peak - valley;
        }
        
        return maxPro;
    }
};

*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxPro = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            
            if (prices[i] > prices[i - 1])
                maxPro += prices[i] - prices[i - 1];
        }
        
        return maxPro;
    }
};

