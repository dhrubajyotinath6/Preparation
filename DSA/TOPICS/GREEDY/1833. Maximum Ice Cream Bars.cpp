
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, 
where costs[i] is the price of the ith ice cream bar in coins. 
The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.


Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.


Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.


/*
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());
        
        int n = costs.size();
        int iceCream = 0;
        
        while(iceCream < n && costs[iceCream] <= coins){
            coins -= costs[iceCream];
            iceCream++;
        }
        
        return iceCream;
    }
};
*/

//2nd approach and more optimal ( Counting Sort (Greedy))

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int n = costs.size();
        int m = *max_element(costs.begin(), costs.end());
        int iceCreams = 0;
        
        vector<int> costsFrequency(m+1, 0);
        for(auto &cost : costs){
            costsFrequency[cost]++;
        }
        
        for(int cost = 1; cost <= m; cost++){
            
            // No ice cream is present costing 'cost'.
            if (costsFrequency[cost] == 0) {
                continue;
            }
            
             // We don't have enough 'coins' to even pick one ice cream.
            if (coins < cost) {
                break;
            }
            
            // Count how many icecreams of 'cost' we can pick with our 'coins'.
            // Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
            int count = min(costsFrequency[cost], coins / cost);
            // We reduce price of picked ice creams from our coins.
            coins -= cost * count;
            iceCreams += count;
        }
        
        return iceCreams;
    }
};