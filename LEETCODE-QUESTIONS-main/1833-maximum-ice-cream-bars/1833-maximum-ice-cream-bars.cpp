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