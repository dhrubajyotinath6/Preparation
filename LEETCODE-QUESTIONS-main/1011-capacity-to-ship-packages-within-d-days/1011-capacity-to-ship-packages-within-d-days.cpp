//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/346505/Binary-classification-Python.-Detailed-explanation-Turtle-Code/1296853

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        int low = 0, high = 0;
        
       for (int w: weights) {
            low = max(low, w);
            high += w;
        }
        
    	int estimatedCapacity = 0;

    	while (low < high) {
    		// estimate the capacity of ship
    		estimatedCapacity = low + (high - low) / 2;

    		int currentWeight = 0; // weight of current ship
    		int estimatedDays = 1; // number of days estimated

    		// -- simulating loading the weight to ship on by one --
    		for (int weight: weights) {
    			currentWeight += weight;
    			if (currentWeight > estimatedCapacity) {
    				estimatedDays += 1;       // current weight on the ship over estimated capacity so we need one more day
    				currentWeight = weight;   // move the latest over weighted package to the ship on the following day
    			}
    		}
    		// -- simulation ends --

    		
    		if (estimatedDays > days)
    			low = estimatedCapacity + 1; // estimated shipping days over target days, we need to increase estimated capacity
    		else
    			high = estimatedCapacity;   // we managed to ship everything within target days, now reducing the estimated capacity to find out optimal
    		
    	}

    	return low;
    }
};